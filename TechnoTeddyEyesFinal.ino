/* COLOR PALETTE: (RGB565 format as used in TFT_eSPI.h)
  magenta / pink: 0XF817
  barbie pink: 0XF813
  
  strong pink:  (base color)
  dark medium strong pink: 0XF916 (a bit lighter)
  medium strong pink: 0XFA78 (lil' more light, etc.)
  light medium strong pink: 0XFB59
  light strong pink: OXFC7B
  much lighter strong pink: 0XFE3D
  lightest strong pink: 0XFF1E

<<---------------------------------->>
  beginning at top-left (0,0):
  X = 0-240 (across)
  Y = 0-240 (down)

  format: (x,y)
  ---------------
  left-top: (0,0) 
  left-middle: (0,120)
  left-bottom: (0,240)

  center / middle: (120,120)
   
  right-top: (240,0)
  right-middle: (240,120)
  right-bottom: (240,240)
*/

#include <TFT_eSPI.h> 

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite iris = TFT_eSprite(&tft);
TFT_eSprite pupil = TFT_eSprite(&tft);

int sound = 0;

void setup() {
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_WHITE);
  tft.setPivot(0,0);
  pupil.createSprite(180,180);
  iris.createSprite(200,200);
}

// int x=0;

void loop() {
  iris.fillSprite(TFT_WHITE);
  iris.fillCircle(95,95,95,TFT_BLACK);
  
  
  pupil.fillSprite(TFT_WHITE);
  pupil.fillCircle(60,60,45,TFT_BLACK);//60 60 45

  pupil.pushRotated(&iris,x,TFT_WHITE);
  iris.pushSprite(25,25); //TOP-LEFT CORNER location OF SPRITE CONTAINER
  // x++;
  // if(x>360)
  // x=0;
  for(int x=0;x<360;x++)

}

void eyeColor(){
  if(sound==1){ //digitalRead(pin#)
    iris.fillCircle(95,95,85,0X079F); //blue
    iris.fillCircle(95,95,65,0X07FF);
  }
  else if(sound==2){
    iris.fillCircle(95,95,85,0XFA78); //pink
    iris.fillCircle(95,95,65,0XFB59);
  }
  else if(sound==2){
    iris.fillCircle(95,95,85,0XFA78); //pink
    iris.fillCircle(95,95,65,0XFB59);
  }
  else if(sound==2){
    iris.fillCircle(95,95,85,0XFA78); //pink
    iris.fillCircle(95,95,65,0XFB59);
  }
  else{
    iris.fillCircle(95,95,85,0XFA78); //pink
    iris.fillCircle(95,95,65,0XFB59);
  }
}


