// J5 Project. Uses libraries Adafruit_GFX and Adafruit_ST7735. Please read license
// and give proper credit accordingly

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>


#define TFT_CS     10
#define TFT_RST    9  
#define TFT_DC     8

// Option 1 (recommended): must use the hardware SPI pins
// (for UNO thats sclk = 13 and sid = 11) and pin 10 must be
// an output. This is much faster - also required if you want
// to use the microSD card (see the image drawing example)
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

// Option 2: use any pins but a little slower!
#define TFT_SCLK 13   // set these to be whatever pins you like!
#define TFT_MOSI 11   // set these to be whatever pins you like!
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);


float p = 3.1415926;

void setup(void) {
  Serial.begin(9600);
  Serial.print("Hello! ST7735 TFT Test");

  // Use this initializer if you're using TFT
  tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab

  Serial.println("Initialized");
  uint16_t time = millis();
  tft.fillScreen(ST7735_BLACK);
  time = millis() - time;
  Serial.println(time, DEC);
  delay(500);


  // Display Dr. Pepper
  printDrPepper();
  delay(4000);

  //Display Dr. Pepper with delay
  printDrPepper_withdelay();
  delay(4000);

  //Rotate display
  rotateText();
  delay(3000);

  printDrPepper();
  delay(4000);

  //Completed setup
  Serial.println("done");
  delay(1000);
}

void loop() {
  //tft.invertDisplay(true);
  //delay(500);
  tft.invertDisplay(false);
  delay(500);
}


void printDrPepper() {
  
  tft.setTextWrap(false);
  tft.fillScreen(ST7735_BLACK);
  tft.setCursor(0, 40);
  tft.setTextColor(ST7735_GREEN);
  tft.setTextSize(1);
  tft.println("RETURN TO D-STATION");
  tft.setCursor(0,60);
  tft.setTextColor(ST7735_GREEN);
  tft.setTextSize(2);
  tft.println("Wouldn't");
  tft.println("you like to");
  tft.println("be a Pepper");
  tft.println("too?");
  
}



void printDrPepper_withdelay() {
  
  tft.setTextWrap(false);
  tft.fillScreen(ST7735_BLACK);
  tft.setCursor(0, 40);
  tft.setTextColor(ST7735_GREEN);
  tft.setTextSize(1);
  delay(500);
  tft.println("RETURN TO D-STATION");
  delay(1000);
  tft.setCursor(0,60);
  tft.setTextColor(ST7735_GREEN);
  tft.setTextSize(2);
  tft.println("Wouldn't");
  delay(700);
  tft.println("you like to");
  delay(700);
  tft.println("be a Pepper");
  delay(700);
  tft.println("too?");
  delay(1500);
  
}

void rotateText() {
  
  for (uint8_t i=0; i<4; i++) {
    tft.fillScreen(ST7735_BLACK);
    tft.setTextWrap(false);
    tft.setCursor(0, 40);
    tft.setTextColor(ST7735_GREEN);
    tft.setTextSize(1);
    tft.println("RETURN TO D-STATION");
    tft.setCursor(0,60);
    tft.setTextColor(ST7735_GREEN);
    tft.setTextSize(2);
    tft.println("Wouldn't");
    tft.println("you like to");
    tft.println("be a Pepper");
    tft.println("too?");
  
    delay(2000);
    tft.setRotation(tft.getRotation()+1);
  }
}



