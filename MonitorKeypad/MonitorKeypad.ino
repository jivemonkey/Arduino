#include <Keypad.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"
#include <Wire.h>

#define Password_Length 8

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

char Data[Password_Length]; 
char Master[Password_Length] = "12C85DA"; 
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;

const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
SSD1306AsciiWire oled;

void setup(){
  Serial.begin(9600);
  Wire.begin();
  Wire.setClock(400000L);
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
  oled.setFont(Arial_bold_14);
  clearData();
}

void loop(){
  customKey = customKeypad.getKey();
  if (customKey){
    Data[data_count] = customKey; 
    oled.print(Data[data_count]);
    data_count++; 
  }

  if(data_count == Password_Length-1) {
    oled.clear();
    oled.set2X();
    if(!strcmp(Data, Master)){
      oled.println("Correct");
    } else {
      oled.println("Incorrect");
    }
    
    delay(3000);   
    clearData();  
  }
}

void clearData() {
  while(data_count !=0){
    Data[data_count--] = 0; 
  }
  oled.clear();
  oled.set1X();
  oled.println("Enter Password:");
  return;
}
