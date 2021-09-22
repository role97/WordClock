#include <Wire.h>
#include "ds3231.h"
#include <Adafruit_NeoPixel.h>
#include <WiFiManager.h>



#define NUMPIXELS 114
#define PIN 6

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif


uint8_t esist[6] = {5, 5, 6, 7, 9, 10};
uint8_t uhr[4] = {3, 107, 108, 109};

uint8_t fuenf_min[5] = {4, 0, 1, 2, 3};
uint8_t zehn_min[5] = {4, 11, 12, 13, 14};
uint8_t zwanzig[8] = {7, 15, 16, 17, 18, 19, 20, 21};

uint8_t dreiviertel[12] = {11, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32};
uint8_t viertel[8] ={7, 22, 23, 24, 25, 26, 27, 28};
uint8_t halb[5] = {4, 51, 52, 53, 54};

uint8_t nach[5] = {4, 35, 36, 37, 38};
uint8_t vor[4] = {3, 39, 40, 41};

uint8_t eins[5] = {4, 57, 58, 59, 60};
uint8_t ein[4]= {3, 57, 58, 59};
uint8_t zwei[5] = {4, 55, 56, 57, 58};
uint8_t drei[5] = {4, 72, 73, 74, 75};
uint8_t vier[5] = {4, 84, 85, 86, 87};
uint8_t fuenf[5] = {4, 66, 67, 68, 69};
uint8_t sechs[6] = {5, 100, 101, 102, 103, 104};
uint8_t sieben[7] = {6, 60, 61, 62, 63, 64, 65};
uint8_t acht[5] = {4, 94, 95, 96, 97};
uint8_t neun[5] = {4, 80, 81, 82, 83};
uint8_t zehn[5] = {4, 90, 91, 92, 93};
uint8_t elf[4] = {3, 77, 78, 79};
uint8_t zwoelf[6] = {5, 45, 46, 47, 48, 49};

int rot = 255;
int gruen = 255;
int blau = 255;

int minute_alt = 10;
int minute_akt = 0;

bool h12Flag;
bool pmFlag;
 
void setup() {
  Serial.begin(9600);
  Wire.begin();
  pixels.begin();
  rtc_start();
  
 // rtc_set_stunde(12);
 // rtc_set_minute(59);
 // setClockMode(1);
  
}
void loop() {
Serial.print(rtc_stunde());
Serial.print(":");
Serial.println(rtc_minute());
delay(1000);
minute_akt = rtc_minute();

if(minute_akt != minute_alt){
  minute_alt = minute_akt;
  switch(minute_akt){
    case 0: case 1: case 2: case 3: case 4:
    pixels.clear(); 
    for(int i = 1; i<= esist[0]; i++){
      pixels.setPixelColor(esist[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= uhr[0]; i++){
      pixels.setPixelColor(uhr[i], pixels.Color(rot, gruen, blau));
    }
    break;
    case 5: case 6: case 7: case 8: case 9: 
    pixels.clear(); 
    for(int i = 1; i<= esist[0]; i++){
      pixels.setPixelColor(esist[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= fuenf_min[0]; i++){
      pixels.setPixelColor(fuenf_min[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= nach[0]; i++){
      pixels.setPixelColor(nach[i], pixels.Color(rot, gruen, blau));
    }
    break;
    case 10: case 11: case 12: case 13: case 14:
    pixels.clear(); 
    for(int i = 1; i<= esist[0]; i++){
      pixels.setPixelColor(esist[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= zehn_min[0]; i++){
      pixels.setPixelColor(zehn_min[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= nach[0]; i++){
      pixels.setPixelColor(nach[i], pixels.Color(rot, gruen, blau));
    }
    break;
    case 15: case 16: case 17: case 18: case 19:
    pixels.clear(); 
    for(int i = 1; i<= esist[0]; i++){
      pixels.setPixelColor(esist[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= viertel[0]; i++){
      pixels.setPixelColor(viertel[i], pixels.Color(rot, gruen, blau));
    }
    break;
    case 20: case 21: case 22: case 23: case 24:
    pixels.clear(); 
    for(int i = 1; i<= esist[0]; i++){
      pixels.setPixelColor(esist[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= zwanzig[0]; i++){
      pixels.setPixelColor(zwanzig[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= nach[0]; i++){
      pixels.setPixelColor(nach[i], pixels.Color(rot, gruen, blau));
    }
    break;
    case 25: case 26: case 27: case 28: case 29:
    pixels.clear(); 
    for(int i = 1; i<= esist[0]; i++){
      pixels.setPixelColor(esist[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= fuenf_min[0]; i++){
      pixels.setPixelColor(fuenf_min[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= vor[0]; i++){
      pixels.setPixelColor(vor[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= halb[0]; i++){
      pixels.setPixelColor(halb[i], pixels.Color(rot, gruen, blau));
    }
    break;
    case 30: case 31: case 32: case 33: case 34:
    pixels.clear(); 
    for(int i = 1; i<= esist[0]; i++){
      pixels.setPixelColor(esist[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= halb[0]; i++){
      pixels.setPixelColor(halb[i], pixels.Color(rot, gruen, blau));
    }
    break;
    case 35: case 36: case 37: case 38: case 39:
    pixels.clear(); 
    for(int i = 1; i<= esist[0]; i++){
      pixels.setPixelColor(esist[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= fuenf_min[0]; i++){
      pixels.setPixelColor(fuenf_min[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= nach[0]; i++){
      pixels.setPixelColor(nach[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= halb[0]; i++){
      pixels.setPixelColor(halb[i], pixels.Color(rot, gruen, blau));
    }
    break;
    case 40: case 41: case 42: case 43: case 44:
    pixels.clear(); 
    for(int i = 1; i<= esist[0]; i++){
      pixels.setPixelColor(esist[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= zwanzig[0]; i++){
      pixels.setPixelColor(zwanzig[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= vor[0]; i++){
      pixels.setPixelColor(vor[i], pixels.Color(rot, gruen, blau));
    }
    break;
    case 45: case 46: case 47: case 48: case 49:
    pixels.clear(); 
    for(int i = 1; i<= esist[0]; i++){
      pixels.setPixelColor(esist[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= dreiviertel[0]; i++){
      pixels.setPixelColor(dreiviertel[i], pixels.Color(rot, gruen, blau));
    }
    break;
    case 50: case 51: case 52: case 53: case 54:
     pixels.clear(); 
    for(int i = 1; i<= esist[0]; i++){
      pixels.setPixelColor(esist[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= zehn_min[0]; i++){
      pixels.setPixelColor(zehn_min[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= vor[0]; i++){
      pixels.setPixelColor(vor[i], pixels.Color(rot, gruen, blau));
    }
    break;
    case 55: case 56: case 57: case 58: case 59:
    pixels.clear(); 
    for(int i = 1; i<= esist[0]; i++){
      pixels.setPixelColor(esist[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= fuenf_min[0]; i++){
      pixels.setPixelColor(fuenf_min[i], pixels.Color(rot, gruen, blau));
    }
    for(int i = 1; i<= vor[0]; i++){
      pixels.setPixelColor(vor[i], pixels.Color(rot, gruen, blau));
    }
    break;
    
    
    
  } 

  switch(minute_akt % 5){
    case 1:
    pixels.setPixelColor(113, pixels.Color(rot, gruen, blau));
    break;
    case 2:
    pixels.setPixelColor(113, pixels.Color(rot, gruen, blau));
    pixels.setPixelColor(110, pixels.Color(rot, gruen, blau));
    break;
    case 3:
    pixels.setPixelColor(113, pixels.Color(rot, gruen, blau));
    pixels.setPixelColor(110, pixels.Color(rot, gruen, blau));
    pixels.setPixelColor(111, pixels.Color(rot, gruen, blau));
    break;
    case 4:
    pixels.setPixelColor(113, pixels.Color(rot, gruen, blau));
    pixels.setPixelColor(110, pixels.Color(rot, gruen, blau));
    pixels.setPixelColor(111, pixels.Color(rot, gruen, blau));
    pixels.setPixelColor(112, pixels.Color(rot, gruen, blau));
    break;
  }

  if((minute_akt == 15 || minute_akt == 16 || minute_akt == 17 || minute_akt == 18 || minute_akt == 19) || (minute_akt >= 25)){
    switch(rtc_stunde()){
      case 0:
      for(int i = 1; i<=eins[0]; i++){
        pixels.setPixelColor(eins[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 1:
      for(int i = 1; i<=zwei[0]; i++){
        pixels.setPixelColor(zwei[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 2:
      for(int i = 1; i<=drei[0]; i++){
        pixels.setPixelColor(drei[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 3:
      for(int i = 1; i<=vier[0]; i++){
        pixels.setPixelColor(vier[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 4:
      for(int i = 1; i<=fuenf[0]; i++){
        pixels.setPixelColor(fuenf[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 5:
      for(int i = 1; i<=sechs[0]; i++){
        pixels.setPixelColor(sechs[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 6:
      for(int i = 1; i<=sieben[0]; i++){
        pixels.setPixelColor(sieben[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 7:
      for(int i = 1; i<=acht[0]; i++){
        pixels.setPixelColor(acht[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 8:
      for(int i = 1; i<=neun[0]; i++){
        pixels.setPixelColor(neun[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 9:
      for(int i = 1; i<=zehn[0]; i++){
        pixels.setPixelColor(zehn[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 10:
      for(int i = 1; i<=elf[0]; i++){
        pixels.setPixelColor(elf[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 11:
      for(int i = 1; i<=zwoelf[0]; i++){
        pixels.setPixelColor(zwoelf[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 12:
      for(int i = 1; i<=eins[0]; i++){
        pixels.setPixelColor(eins[i], pixels.Color(rot, gruen, blau));
        }
      break;
    }
  }
  else if(minute_akt < 15 || minute_akt == 20 || minute_alt == 21 || minute_alt == 22 || minute_alt == 23 || minute_alt == 24){
    switch(rtc_stunde()){
      case 0:
      for(int i = 1; i<=zwoelf[0]; i++){
        pixels.setPixelColor(zwoelf[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 1:
      if(minute_akt == 0 || minute_akt == 1 || minute_akt == 2 || minute_akt == 3 || minute_akt == 4){
        for(int i = 1; i<= ein[0]; i++){
          pixels.setPixelColor(ein[i], pixels.Color(rot, gruen, blau));
        }}
        else{
      for(int i = 1; i<=eins[0]; i++){
        pixels.setPixelColor(eins[i], pixels.Color(rot, gruen, blau));
        }}
      break;
      case 2:
      for(int i = 1; i<=zwei[0]; i++){
        pixels.setPixelColor(zwei[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 3:
      for(int i = 1; i<=drei[0]; i++){
        pixels.setPixelColor(drei[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 4:
      for(int i = 1; i<=vier[0]; i++){
        pixels.setPixelColor(vier[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 5:
      for(int i = 1; i<=fuenf[0]; i++){
        pixels.setPixelColor(fuenf[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 6:
      for(int i = 1; i<=sechs[0]; i++){
        pixels.setPixelColor(sechs[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 7:
      for(int i = 1; i<=sieben[0]; i++){
        pixels.setPixelColor(sieben[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 8:
      for(int i = 1; i<=acht[0]; i++){
        pixels.setPixelColor(acht[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 9:
      for(int i = 1; i<=neun[0]; i++){
        pixels.setPixelColor(neun[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 10:
      for(int i = 1; i<=zehn[0]; i++){
        pixels.setPixelColor(zehn[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 11:
      for(int i = 1; i<=elf[0]; i++){
        pixels.setPixelColor(elf[i], pixels.Color(rot, gruen, blau));
        }
      break;
      case 12:
      for(int i = 1; i<=zwoelf[0]; i++){
        pixels.setPixelColor(zwoelf[i], pixels.Color(rot, gruen, blau));
        }
      break;
      
    }
  }
  }
  pixels.show();
}
