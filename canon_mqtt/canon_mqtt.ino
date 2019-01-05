#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "SparkleKitty";
const char* password = "H0tM0nkeyL0ve";
const char* mqtt_server = "192.168.0.40";
const char* ip_reg = "ipreg";
const char* canon_state = "canon_state";
const int CANON_PIN = BUILTIN_LED;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  pinMode(CANON_PIN, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  digitalWrite(CANON_PIN, HIGH);
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  //  Force the ESP into client-only mode
  WiFi.mode(WIFI_STA);
  WiFi.setSleepMode(WIFI_LIGHT_SLEEP);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Switch on the LED if an 1 was received as first character
  if ((char)payload[0] == '1') {
    digitalWrite(CANON_PIN, LOW);   // Turn the LED on (Note that LOW is the voltage level
    // but actually the LED is on; this is because
    // it is acive low on the ESP-01)
    delay(1000);
    digitalWrite(CANON_PIN, HIGH);
    client.publish(canon_state, "0", true);
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("CanonClient")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      char buf[16];
      sprintf(buf, "IP:%d.%d.%d.%d", WiFi.localIP()[0], WiFi.localIP()[1], WiFi.localIP()[2], WiFi.localIP()[3] );
      client.publish(ip_reg, buf, true);
      // ... and resubscribe
      client.subscribe(canon_state);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(1000);
    }
  }
}
void loop() {

  if (!client.connected()) {
    reconnect();
  }
  
  client.loop();
  Serial.println("sleep");
  delay(2000);
  Serial.println("wake");
  //ESP.deepSleep(1000);
}
