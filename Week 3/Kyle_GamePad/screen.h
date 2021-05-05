#include "SPI.h"
#include "ILI9341_t3n.h"

#define TFT_DC  9
#define TFT_CS  10
#define TFT_RST 8

ILI9341_t3n tft = ILI9341_t3n(TFT_CS, TFT_DC, TFT_RST);

#define screenW  320
#define screenH  240
DMAMEM uint16_t screenBuffer[screenW * screenH];   // Screen Buffer

Metro colChange = Metro(1000);
Metro colChange2 = Metro(1000);
int cChange=0;

void initScreen(){
  tft.begin();                            // Connect to LCD Screen
  tft.setRotation(1);                   // Rotate Screen 90 Degrees
  
  tft.setFrameBuffer(screenBuffer);   // Initialize Frame Buffer
  tft.useFrameBuffer(1);                // Use Frame Buffer

  tft.fillScreen(ILI9341_BLACK);
  tft.updateScreen(); // Clear Screen
}


void screenTest(){
  
  if(colChange.check()==true){
    cChange= (cChange+1)%2;
  }
  if(cChange==0){
    tft.fillScreen(ILI9341_WHITE);
  } else if(cChange==1){
    tft.fillScreen(ILI9341_BLACK);
  }
}
