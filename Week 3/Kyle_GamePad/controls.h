#include <Bounce2.h>
int buttonBounce = 10;
Bounce * buttons = new Bounce[4];

int buttonPins [4] {0,1,2,3};
int buttonBuffers [4]{0,0,0,0};
int joistickPins [2] {14,15};
int joistickBuffers [2] {0,0};

int bigX = 0;
int bigY = 1;

void initControls(){
 for(int i=0; i<4; i++){
  buttons[i].attach(buttonPins[i], INPUT_PULLUP);
  buttons[i].interval(buttonBounce);
 }
}

void getControls(){
 for(int i=0;i<4;i++){
  if (buttons[i].fell()==true){
    buttonBuffers [i] = 0;
    Serial.println("LMAO"+i);
  } 
  if (buttons[i].rose()==true){
    buttonBuffers [i] = 1;
    Serial.println("OMG"+i);
  }
 }
}

void initlogs(){
  if(analogRead(14)<300){
  bigX = -1;
 } else if (analogRead(14)>800){
  bigX = 1;
 } else {
  bigX = 0;
 }

  if(analogRead(15)<300){
  bigY = 1;
 } else if (analogRead(15)>800){
  bigY = -1;
 } else {
  bigY = 0;
 }
}

void butUpdate(){
for(int i=0;i<4;i++){
  buttons[i].update();
}
}
