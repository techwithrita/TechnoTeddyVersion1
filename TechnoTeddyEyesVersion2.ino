// Animated GIF with Round Display
#include <SPI.h>
#include <TFT_eSPI.h>
#include "AnimatedGIF.h"

// #include "images/lgPink.h"
// #include "images/lgPinkWide.h" 
#include "images/lgPinkSad.h" 
// #include "images/lgPinkRight.h"
// #include "images/lgPinkLeft.h"
// #include "images/lgPinkUp.h"
// #include "images/lgPinkDown.h"
// #include "images/TechEyesGif.h"
#include "images/lgPinkHeart.h"
#include "images/lgPinkTech1.h"
#include "images/lgPinkTech2.h"
#include "images/closedEye.h"

// Adjust this value based on the number of displays
const int NUM_DISPLAYS = 2;
// Add more CS pins if you have more displays, each display must have a dedicated pin
const int CS_PINS[NUM_DISPLAYS] = {19, 22};
int currentScreenIndex = 0;

// AnimatedGIF gif_1;
// AnimatedGIF gif_2;
AnimatedGIF gif_3;
// AnimatedGIF gif_4;
// AnimatedGIF gif_5;
// AnimatedGIF gif_6;
// AnimatedGIF gif_7;
// AnimatedGIF gif_8;
AnimatedGIF gif_9;
AnimatedGIF gif_10;
AnimatedGIF gif_11;
AnimatedGIF gif_12;


TFT_eSPI tft = TFT_eSPI();

unsigned long lastFrameSpeed = 0;

void setup() {
  Serial.begin(115200);

  tft.init();
  for (int i = 0; i < NUM_DISPLAYS; i++) {
    pinMode(CS_PINS[i], OUTPUT);
    digitalWrite(CS_PINS[i], LOW);  // select the display
    tft.fillScreen(TFT_BLACK);
    //find a way to rotate only 1 screen
    tft.setRotation(3);              // Adjust Rotation of your screen (0-3)
    digitalWrite(CS_PINS[i], HIGH);  // Deselect the display
  }
    //run the above AnimatedGifs through the open function
    //to open them 
    // openGif(&gif_1, lgPink, sizeof(lgPink));
    // openGif(&gif_2, lgPinkWide, sizeof(lgPinkWide));
    openGif(&gif_3, lgPinkSad, sizeof(lgPinkSad));
    // openGif(&gif_4, lgPinkRight, sizeof(lgPinkRight));
    // openGif(&gif_5, lgPinkLeft, sizeof(lgPinkLeft));
    // openGif(&gif_6, lgPinkUp, sizeof(lgPinkUp));
    // openGif(&gif_7, lgPinkDown, sizeof(lgPinkDown));
    // openGif(&gif_8, TechEyesGif, sizeof(TechEyesGif));
    openGif(&gif_9, lgPinkHeart, sizeof(lgPinkHeart));
    openGif(&gif_10, lgPinkTech1, sizeof(lgPinkTech1));
    openGif(&gif_11, lgPinkTech2, sizeof(lgPinkTech2));
    openGif(&gif_12, closedEye, sizeof(closedEye));
}
void loop() {
  /* ADD FUNCTIONALITY:
    Change color of pinks to blues, without having to transition to other blue .gif eye 
    files. There is a way to create function that converts colors in these libraries. 
    Must find out how. 
  */ 

  // //regular
  // playGif(&gif_1, 0);
  // playGif(&gif_1, 1);
  // delay(7500);
  // //wide 
  // playGif(&gif_2, 0);
  // playGif(&gif_2, 1);
  // delay(5500);

  //closed / blink
  playGif(&gif_12, 0);
  playGif(&gif_12, 1);
  delay(500);

  //regular
  playGif(&gif_10, 0);
  playGif(&gif_11, 1);
  delay(2500);
  //sad
  playGif(&gif_3, 0);
  playGif(&gif_3, 1);
  delay(5500);
  // //right 
  // playGif(&gif_4, 0);
  // playGif(&gif_4, 1);
  // delay(5500);
  // //left
  // playGif(&gif_5, 0);
  // playGif(&gif_5, 1);
  // delay(5500);

  //closed / blink
  playGif(&gif_12, 0);
  playGif(&gif_12, 1);
  delay(500);

  // //up
  // playGif(&gif_6, 0);
  // playGif(&gif_6, 1);
  // delay(5500);
  // //down
  // playGif(&gif_7, 0);
  // playGif(&gif_7, 1);
  // delay(5500);
  // //techno-teddy one eye
  // playGif(&gif_8, 0);
  // playGif(&gif_1, 1);
  // delay(3500);
  //heart
  playGif(&gif_9, 0);
  playGif(&gif_9, 1);
  delay(3500);
  //heart
  playGif(&gif_10, 0);
  playGif(&gif_10, 1);
  delay(3500);
  //heart
  playGif(&gif_11, 0);
  playGif(&gif_11, 1);
  delay(3500);


  //closed / blink
  playGif(&gif_12, 0);
  playGif(&gif_12, 1);
  delay(500);

}

void openGif(AnimatedGIF *gif, const uint8_t *gifImage, int gifSize) {
  gif->begin(BIG_ENDIAN_PIXELS);
  if (!gif->open((uint8_t *)gifImage, gifSize, GIFDraw)) {
    Serial.printf("Could not open gif \n");
  }
}

void playGif(AnimatedGIF *gif, int screenIndex) {
  currentScreenIndex = screenIndex;
  int res = gif->playFrame(false, NULL);
  if (res == 0) {
    // If no more frames are available, reset the GIF to the beginning
    gif->reset();
    gif->playFrame(false, NULL);
  }
  if (res == -1) {
    Serial.printf("Gif Error = %d on screen %d\n", gif->getLastError(), screenIndex);
  }
  
  //to see frame rates / speed, uncomment this function
  // else leave vacant as this uses up space / resources on board (even if just a little)
  // if (screenIndex == 0) {
  //   if (lastFrameSpeed == 0) {
  //     lastFrameSpeed = millis();
  //   } else {
  //     Serial.printf("Screen 0 FPS=%f\n", 1000.0f / (millis() - lastFrameSpeed));
  //     lastFrameSpeed = millis();
        
  //   }
  // }
}
