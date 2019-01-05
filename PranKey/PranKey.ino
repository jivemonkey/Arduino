#include "DigiKeyboard.h"

void setup() {
  // don't need to set anything up to use DigiKeyboard
}


void loop() {
  // this is generally not necessary but with some older systems it seems to
  // prevent missing the first character after a delay:
  //DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(43, MOD_GUI_LEFT);

  // It's better to use DigiKeyboard.delay() over the regular Arduino delay()
  // if doing keyboard stuff because it keeps talking to the computer to make
  // sure the computer knows the keyboard is alive and connected
  //Hello Digispark!
  DigiKeyboard.delay(10000);
}
