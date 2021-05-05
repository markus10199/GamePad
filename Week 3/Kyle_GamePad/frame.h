#include <Metro.h> 
Metro checkLoop = Metro(1000); 

int checkCount;
void checkFrame(){
  checkCount++;
  if(checkLoop.check()){
    Serial.println(checkCount);
  }
}
