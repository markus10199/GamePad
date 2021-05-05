#include "MainC-Enemy_Mask.h"
#include "MainC-Enemy_PIX.h"
int incX=0;
int incY=0;
int HeroPosX=screenW/2;
int HeroPosY=screenH/2;
Metro charMove(25);
int isLevelDrawn = false;
int level = 0;
int levchange = 0;
int canIMove =false;

void drawHero(){
  if(charMove.check()==true){
    canIMove=true;
  }
  if(canIMove==true){
  if(bigX==-1){
    incX++;
    if (incX==2){
      incX=1;
    }
    HeroPosX = HeroPosX-incX;
  } else  if(bigX==1){
    incX++;
    if (incX==2){
      incX=1;
    }
    HeroPosX = HeroPosX+incX;
  }
    if(bigY==-1){
    incY++;
    if (incY==2){
      incY=1;
    }
    HeroPosY = HeroPosY-incY;
  } else  if(bigY==1){
    incY++;
    if (incY==2){
      incY=1;
    }
    HeroPosY = HeroPosY+incY;
  }
  canIMove=false;
  }
  if (HeroPosX<=0){
    HeroPosX=1;
  } else if (HeroPosX>=screenW-20){
    HeroPosX=screenW-21;
  }
    if (HeroPosY<=0){
    HeroPosY=1;
  } else if (HeroPosY>=screenH-20){
    HeroPosY=screenH-21;
  }
  drawLevel(level);
  if (isLevelDrawn==false){
    tft.updateScreen();
    isLevelDrawn=true;
  }
  tft.setClipRect(HeroPosX-1,HeroPosY-1,tileSize+2,tileSize+2);
  tft.drawRGBBitmap(HeroPosX,HeroPosY,MainC_Enemy_PIX[0],tileSize,tileSize);//,MainC_Enemy_MASK[0]); //
  tft.updateScreen();
}
