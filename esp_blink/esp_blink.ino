#include <ESP8266WiFi.h>
#include <esp8266httpclient.h>
#include <Wire.h>

#define D0 16
#define D1 5 // I2C Bus SCL (clock)
#define D2 4 // I2C Bus SDA (data)
#define D3 0
#define D4 2 // Same as "LED_BUILTIN", but inverted logic
#define D5 14 // SPI Bus SCK (clock)
#define D6 12 // SPI Bus MISO 
#define D7 13 // SPI Bus MOSI
#define D8 15 // SPI Bus SS (CS)
#define D9 3 // RX0 (Serial console)
#define D10 1 // TX0 (Serial console)

const char* ssid = "SpaceUnicorn";
const char* password = "roc8roll";
int value = LOW;
WiFiServer server(80);

void setup() {
  Wire.begin(D1, D2);
  Serial.begin(115200);

  // Connect to WiFi network
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");

  HTTPClient http;
  http.begin("http://www.hippokiss.us/register/");
  http.addHeader("Content-Type", "text/plain");
  http.post("");
}
 
void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  // Match the request
 
  if (request.indexOf("/off") != -1)  {
    Wire.write("off");
    Serial.println("Turn Off");
    value = HIGH;
  }
  if (request.indexOf("/on") != -1)  {
    Wire.write("on");
    Serial.println("Turn On");
    value = LOW;
  }
 
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
 
  client.print("Led pin is now: ");
  
  client.println("<br><br>");
  client.println("<a href=\"/off\"\"><button>Off</button></a>");
  client.println("<a href=\"/on\"\"><button>On</button></a><br />");  
  client.println("</html>");
 
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
 
}
 
