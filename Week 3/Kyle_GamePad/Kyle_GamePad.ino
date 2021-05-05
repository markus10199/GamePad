//Project Hellscape
//Kyle Sullivan || March 29, 2021
//CRT 360 Advanced Prototyping || GamePad

int curMode=-1;

#include "frame.h"
#include "screen.h"
#include "tiles.h"
#include "controls.h"
#include "hero.h"
#include "modes.h"



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  initScreen();
  initControls();
}

void loop() {
  // put your main code here, to run repeatedly:
   
  checkFrame();
  int analogx = analogRead(14);
  int analogy = analogRead(15);
  int buts = digitalRead(0)+digitalRead(1)+digitalRead(2)+digitalRead(3);
  Serial.print(buts);
  //tft.updateScreen();
  getControls();
  initlogs();
 butUpdate();
  drawHero();
}
