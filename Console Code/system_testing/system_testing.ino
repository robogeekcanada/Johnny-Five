// J5 Project. Uses libraries Adafruit_GFX and Adafruit_ST7735. Please read license
// and give proper credit accordingly

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library
#include <SPI.h>


#define TFT_CS     10
#define TFT_RST    9  
#define TFT_DC     8

#define BLACK   0x0000
#define RED     0x001F
#define BLUE    0xF800
#define GREEN   0x07E0
#define YELLOW  0x07FF
#define PURPLE  0xF81F
#define CYAN    0xFFE0  
#define WHITE   0xFFFF


// Option 1 (recommended): must use the hardware SPI pins
// (for UNO thats sclk = 13 and sid = 11) and pin 10 must be
// an output. This is much faster - also required if you want
// to use the microSD card (see the image drawing example)
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS,  TFT_DC, TFT_RST);

// Option 2: use any pins but a little slower!
#define TFT_SCLK 13   // set these to be whatever pins you like!
#define TFT_MOSI 11   // set these to be whatever pins you like!
//Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);


int section = 1; //section to print messages

float p = 3.1415926;

void setup(void) {

  // Use this initializer if you're using TFT
  tft.initR(INITR_BLACKTAB);   // initialize a ST7735S chip, black tab
  tft.fillScreen(ST7735_BLACK);

  print_labels();
  draw_buttons();
  delay(1000);

  animate_messages(200,50);
  print_all_messages();
  delay(3000);

}


void loop() {
  
  tft.invertDisplay(false);
}


void print_all_messages(){
   
  for (uint8_t i=0; i<11; i++) {    
    print_messages(i,RED);
  }
}

void print_messages(uint8_t section, uint16_t color){

  tft.setTextSize(1);
  tft.setTextColor(color);
  
  //System label first column
  
  if(section == 1){
    tft.setCursor(13,58);
    tft.println("ELEC.SYS");
    tft.setCursor(13,66);
    tft.println("HYDR.SYS");
  }
  if(section == 2){
    tft.setCursor(13,74);
    tft.println("THRM.SYS");
    tft.setCursor(13,82);
    tft.println("PWR.FUEL");
  }
  if(section == 3){
    tft.setCursor(13,90);
    tft.println("VID/AUD");
    tft.setCursor(13,98);
    tft.println("COMPRSR");
  }
  if(section == 4){
    tft.setCursor(13,106);
    tft.println("REMOTE"); 
    tft.setCursor(13,114);
    tft.println("DATA.HLD");
  }
  if(section == 5){
    tft.setCursor(13,122);
    tft.println("MTR.RFLX"); 
    tft.setCursor(13,130);
    tft.println("TACTICAL");
  }
  

  //System label second column
  //tft.setTextColor(RED);
  if(section == 6){
    tft.setCursor(70,58);
    tft.println("WEAPONS");
    tft.setCursor(70,66);
    tft.println("LASER");
  }
  if(section == 7){
    tft.setCursor(70,74);
    tft.println("TARGET");
    tft.setCursor(70,82);
    tft.println("RADAR");
  }
  if(section == 8){
    tft.setCursor(70,90);
    tft.println("NITE.VIS");
    tft.setCursor(70,98);
    tft.println("STINGER");
  }
  if(section == 9){
    tft.setCursor(70,106);
    tft.println("ASSAULT"); 
    tft.setCursor(70,114);
    tft.println("CNI.CTRL");
  }
  if(section == 10){
    tft.setCursor(70,122);
    tft.println("PHS.SHFT"); 
    tft.setCursor(70,130);
    tft.println("DIGITAL");
  }
  
}


void print_labels(){

  tft.fillScreen(ST7735_BLACK);
  tft.setTextSize(1);

  //System label
  tft.setTextColor(YELLOW);
  tft.setCursor(44,35);
  tft.println("SYSTEMS");
  tft.setCursor(46,43);
  tft.println("TESTING");

  //Standby label
  tft.setTextSize(1);
  tft.setTextColor(RED);
  tft.setCursor(13,147);
  tft.println("STANDBY");

}


void draw_buttons(){

  //Red button left of System Test label
  tft.fillRect(25, 35, 13, 15, RED);

  //Red and yellow buttons right of System Test label
  tft.fillRect(105, 35, 13, 6, RED);
  tft.fillRect(105, 43, 13, 6, YELLOW); 

  //Rectangle around left red button and system test label
  tft.drawLine(10,32,10,52, RED);
  tft.drawLine(10,52,98,52, RED);
  tft.drawLine(98,52,98,32, RED);
  tft.drawLine(98,32,10,32, RED);

  //Rectangle around counter
  tft.drawLine(10,55,10,138, WHITE);
  tft.drawLine(10,138,122,138, WHITE);
  tft.drawLine(122,138,122,55, WHITE);
  tft.drawLine(122,55,10,55, WHITE);

  //shape around ON label
  tft.drawLine(10,140,10,157, WHITE);
  tft.drawLine(10,157,58,157, WHITE);
  tft.drawLine(58,157,56,150, WHITE);
  tft.drawLine(56,150,58,140, WHITE);
  tft.drawLine(58,140,10,140, WHITE);

  //shape around OFF label
  tft.drawLine(122,140,122,157, WHITE);
  tft.drawLine(122,157,77,157, WHITE);
  tft.drawLine(77,157,81,150, WHITE);
  tft.drawLine(81,150,77,140, WHITE);
  tft.drawLine(77,140,122,140, WHITE);

  //Red button bewteen ON and OFF
  tft.fillCircle(68, 150, 8, RED);
  
}


void animate_messages(uint8_t on_time, uint8_t off_time ){
  
  //Sequence: 5,3,9,7,4,10,8,2,1,6
  print_messages(5, RED);
  delay(on_time);
  print_messages(3, RED);
  delay(on_time);
  print_messages(5, BLACK);
  delay(off_time);
  print_messages(3,BLACK);
  delay(off_time);

  print_messages(9,RED);
  delay(on_time);
  print_messages(7,RED);
  delay(on_time);
  print_messages(9,BLACK);
  delay(off_time);
  print_messages(7,BLACK);
  delay(off_time);
  
  print_messages(4,RED);
  delay(on_time);
  print_messages(10,RED);
  delay(on_time);
  print_messages(4,BLACK);
  delay(off_time);
  print_messages(10,BLACK);
  delay(off_time);
  
  print_messages(8,RED);
  delay(on_time);
  print_messages(2,RED);
  delay(on_time);
  print_messages(8,BLACK);
  delay(off_time);
  print_messages(2,BLACK);
  delay(off_time);
  
  print_messages(1,RED);
  delay(on_time);
  print_messages(6,RED);
  delay(on_time);
  print_messages(1,BLACK);
  delay(off_time);
  print_messages(6,BLACK);
  delay(off_time);
 
}

