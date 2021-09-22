
void rtc_start(void)
{
  Wire.beginTransmission(0x68);
  Wire.write(0x0E);
  Wire.write(0x00);				//SqareWave 1Hz aktivieren
  Wire.endTransmission();
}
uint8_t rtc_minute(void)
{
  //Wire.begin();
  uint8_t minute = 0;
  Wire.beginTransmission(0x68);
  Wire.write(0x01);
  Wire.endTransmission();
  Wire.requestFrom(0x68, 1);    // request 6 bytes from slave device #2
  minute = Wire.read();    // receive a byte as character
  minute = (((minute & 0xF0)>>4)*10) + (minute & 0x0F);
  return minute;     
}
uint8_t rtc_sekunde(void)
{
  //Wire.begin();
  uint8_t sekunde = 0;
  Wire.beginTransmission(0x68);
  Wire.write(0x00);
  Wire.endTransmission();
  Wire.requestFrom(0x68, 1);    // request 6 bytes from slave device #2
  sekunde = Wire.read();    // receive a byte as character
  sekunde = (((sekunde & 0xF0)>>4)*10) + (sekunde & 0x0F);
  return sekunde;     
}

uint8_t rtc_stunde(void)
{
  //Wire.begin();
  uint8_t stunde = 0;
  Wire.beginTransmission(0x68);
  Wire.write(0x02);
  Wire.endTransmission();
  Wire.requestFrom(0x68, 1);    // request 6 bytes from slave device #2
  stunde = Wire.read();    // receive a byte as character
  stunde = stunde & 0x1F;
  stunde = (((stunde & 0xF0)>>4)*10) + (stunde & 0x0F);
  return stunde;     
}

void rtc_set_stunde(uint8_t stunde)
{
  stunde = (((stunde /10)*16)+(stunde%10));
  
  Wire.beginTransmission(0x68);
  Wire.write(0x02);
  Wire.write(stunde);
  Wire.endTransmission();
}

void rtc_set_minute(uint8_t minute)
{
  minute = ((minute /10*16)+(minute%10));
  
  Wire.beginTransmission(0x68);
  Wire.write(0x01);
  Wire.write(minute);
  Wire.endTransmission();
}

void rtc_set_sekunde(uint8_t sekunde)
{
  sekunde = ((sekunde /10*16)+(sekunde%10));
  
  Wire.beginTransmission(0x68);
  Wire.write(0x00);
  Wire.write(sekunde);
  Wire.endTransmission();
}

uint8_t rtc_jahr(void)
{
  uint8_t jahr = 0;
  Wire.beginTransmission(0x68);
  Wire.write(0x06);
  Wire.endTransmission();
  Wire.requestFrom(0x68, 1);    // request 6 bytes from slave device #2
  jahr = Wire.read();    // receive a byte as character
  
  jahr = (((jahr & 0xF0)>>4)*10) + (jahr & 0x0F);
  return jahr;   
}

uint8_t rtc_tag(void)
{
  uint8_t tag = 0;
  Wire.beginTransmission(0x68);
  Wire.write(0x04);
  Wire.endTransmission();
  Wire.requestFrom(0x68, 1);    // request 6 bytes from slave device #2
  tag = Wire.read();    // receive a byte as character
  
  tag = (((tag & 0xF0)>>4)*10) + (tag & 0x0F);
  return tag;   
}

uint8_t rtc_monat(void)
{
  uint8_t monat = 0;
  Wire.beginTransmission(0x68);
  Wire.write(0x05);
  Wire.endTransmission();
  Wire.requestFrom(0x68, 1);    // request 6 bytes from slave device #2
  monat = Wire.read();    // receive a byte as character
  
  monat = (((monat & 0xF0)>>4)*10) + (monat & 0x0F);
  return monat;   
}

void rtc_set_jahr(uint8_t jahr)
{
  jahr = ((jahr /10*16)+(jahr%10));
  
  Wire.beginTransmission(0x68);
  Wire.write(0x06);
  Wire.write(jahr);
  Wire.endTransmission();
}

void rtc_set_monat(uint8_t monat)
{
  monat = ((monat /10*16)+(monat%10));
  
  Wire.beginTransmission(0x68);
  Wire.write(0x05);
  Wire.write(monat);
  Wire.endTransmission();
}

void rtc_set_tag(uint8_t tag)
{
  tag = ((tag /10*16)+(tag%10));
  
  Wire.beginTransmission(0x68);
  Wire.write(0x04);
  Wire.write(tag);
  Wire.endTransmission();
}

void setClockMode(bool h12) {
  
  byte temp_buffer;

  // Start by reading byte 0x02.
  Wire.beginTransmission(0x68);
  Wire.write(0x02);
  Wire.endTransmission();
  Wire.requestFrom(0x68, 1);
  temp_buffer = Wire.read();

  // Set the flag to the requested value:
  if (h12) {
    temp_buffer = temp_buffer | 0b01000000;
  } else {
    temp_buffer = temp_buffer & 0b10111111;
  }

  // Write the byte
  Wire.beginTransmission(0x68);
  Wire.write(0x02);
  Wire.write(temp_buffer);
  Wire.endTransmission();
}
