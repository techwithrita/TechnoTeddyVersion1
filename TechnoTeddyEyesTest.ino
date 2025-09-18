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

img.pushSprite(25,25); //puts the top left corner of sprite container in the position to make all 4 spaces even on TFT display (square sprite is centered)
  img.pushSprite(10,10); //for 220x220 sprite dimmentions (OVERALL CONTAINER DIMMENSION)
*/

#include <TFT_eSPI.h> 

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite iris = TFT_eSprite(&tft);
TFT_eSprite pupil = TFT_eSprite(&tft);

void setup() {
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_WHITE);
  tft.setPivot(120, 120);

  iris.setColorDepth(16);
  iris.createSprite(225, 225); //dimmensions of the entire container element, not the created content within
  
  // tft.fillSmoothCircle(120, 120, 95, 0XF815, 0XFA78); //create pink circle for iris in middle
  // tft.fillSmoothCircle(120, 120, 80, 0XFA78, 0XF815); //staggered lighter shade(s) to give depth
  //  //the pupil (black center circle)
  // tft.fillSmoothCircle(120, 120, 40, TFT_BLACK, TFT_DARKGREY); //pupil in very front & center
  // tft.fillSmoothCircle(50, 30, 50, TFT_WHITE, TFT_WHITE); //light glare
  // tft.fillSmoothCircle(100, 100, 25, TFT_WHITE, TFT_WHITE);
 
}

// int angle=0;

void loop() {
  iris.fillSprite(TFT_WHITE); //container's background color
  iris.fillSmoothCircle(110,110,100,TFT_BLACK); //first two #s are x,y coords [(0,0) being top left], next # is diameter of circle, last # is color in hex or name
  iris.fillSmoothCircle(110,109,90,0XF815);
  iris.fillSmoothCircle(109,109,70,0XFB59);
  // iris.fillSmoothCircle(109,109,70,TFT_TRANSPARENT);

  pupil.drawCircle(110,110,60,TFT_TRANSPARENT);
  
  
  iris.pushSprite(10,10); //puts the top left corner of sprite container in designated loc on screen (x,y)
  delay(500);
}
