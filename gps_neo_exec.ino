#include <avr/pgmspace.h>
const int dayofmonth2020[] PROGMEM = {31,29,31,30,31,30,31,31,30,31,30,31};
const int dayofmonth2021[] PROGMEM = {31,28,31,30,31,30,31,31,30,31,30,31};
const int dayofmonth2022[] PROGMEM = {31,28,31,30,31,30,31,31,30,31,30,31};
const int dayofmonth2023[] PROGMEM = {31,28,31,30,31,30,31,31,30,31,30,31};
const int dayofmonth2024[] PROGMEM = {31,29,31,30,31,30,31,31,30,31,30,31};
const int dayofmonth2025[] PROGMEM = {31,28,31,30,31,30,31,31,30,31,30,31};

#include <TinyGPS++.h>
//#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

const int rs = 7, en = 8, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//static const int RXPin=19,TXPin=18;
static const uint32_t GPSBaud=9600;
//the TinyGPS++ object
TinyGPSPlus gps;
//SoftwareSerial ss(RXPin,TXPin);


static double lat1;
static double lon1;
static double alt1;
static double sat1;
static double year;
static double month;
static double day;
static double passingdays;

void setup()
{
  Serial.begin(9600);
  Serial1.begin(GPSBaud);
  lcd.begin(16, 2);
}

void loop()
{
  
  neo_6m_gps(); 
 
     
}
void neo_6m_gps(void)
{
  while(Serial1.available()>0)
  {
       char data=Serial1.read();
       gps.encode(data);
       if(gps.location.isUpdated() && gps.altitude.isUpdated())
       {
          lat1=gps.location.lat();
          lon1=gps.location.lng();
          alt1=gps.altitude.kilometers();
          sat1=gps.satellites.value();
          year=gps.date.year();
          month=gps.date.month();
          day=gps.date.day();

          passing_day();
           
          Serial.println(); 
          Serial.print("Passing_day= ");Serial.println(passingdays); 
          Serial.println(); 
    
          Serial.print("Latitude= ");Serial.println(lat1,6);
          Serial.print("Longitude= ");Serial.println(lon1,6);
          Serial.print("Altitude in kilometers= ");Serial.println(alt1);
          Serial.print("Number of satellites in use = ");Serial.println(sat1);
          Serial.print("Year = "); Serial.println(year);
          Serial.print("Month = "); Serial.println(month);
          Serial.print("Day = "); Serial.println(day);
           

          lcd.setCursor(0, 0);
          lcd.print(lat1,6);lcd.print(",");lcd.print(alt1);
          lcd.setCursor(0, 1);
          lcd.print(lon1,6);lcd.print(",");lcd.print(sat1);

         
       }
    }
    
}

void passing_day(void)
{
    int int_year=(int)year;
    int int_month=(int)month;
    int int_day=(int)day;

    int numberofdays[12];
    int sumofdays[12]={0,0,0,0,0,0,0,0,0,0,0,0,};   
      
    if(year==2020)
    {
      for(int k=0;k<12;k++)
      {
         numberofdays[k]= pgm_read_word_near(dayofmonth2020 + k);
      }
      
      if(int_month=1) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[0] +=numberofdays[i];
        }
        sumofdays[0] +=int_day;
        passingdays=(double)sumofdays[0];
      }
      if(int_month=2) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[1] +=numberofdays[i];
        }
        sumofdays[1] +=int_day;
        passingdays=(double)sumofdays[1];
      }
      if(int_month=3) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[2] +=numberofdays[i];
        }
        sumofdays[2] +=int_day;
        passingdays=(double)sumofdays[2];
      }
      if(int_month=4) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[3] +=numberofdays[i];
        }
        sumofdays[3] +=int_day;
        passingdays=(double)sumofdays[3];
      }
      if(int_month=5) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[4] +=numberofdays[i];
        }
        sumofdays[4] +=int_day;
        passingdays=(double)sumofdays[4];
      }
      if(int_month=6) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[5] +=numberofdays[i];
        }
        sumofdays[5] +=int_day;
        passingdays=(double)sumofdays[5];
      }
      if(int_month=7) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[6] +=numberofdays[i];
        }
        sumofdays[6] +=int_day;
        passingdays=(double)sumofdays[6];
      }
      if(int_month=8) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[7] +=numberofdays[i];
        }
        sumofdays[7] +=int_day;
        passingdays=(double)sumofdays[7];
      }
      if(int_month=9) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[8] +=numberofdays[i];
        }
        sumofdays[8] +=int_day;
        passingdays=(double)sumofdays[8];
      }
      if(int_month=10) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[9] +=numberofdays[i];
        }
        sumofdays[9] +=int_day;
        passingdays=(double)sumofdays[9];
      }
      if(int_month=11) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[10] +=numberofdays[i];
        }
        sumofdays[10] +=int_day;
        passingdays=(double)sumofdays[10];
      }
      if(int_month=12) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[11] +=numberofdays[i];
        }
        sumofdays[11] +=int_day;
        passingdays=(double)sumofdays[11];
      }
   }
   
   if(year==2021)
    {
      for(int k=0;k<12;k++)
      {
         numberofdays[k]= pgm_read_word_near(dayofmonth2021 + k);
      }
      
      if(int_month=1) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[0] +=numberofdays[i];
        }
        sumofdays[0] +=int_day;
        passingdays=(double)sumofdays[0];
      }
      if(int_month=2) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[1] +=numberofdays[i];
        }
        sumofdays[1] +=int_day;
        passingdays=(double)sumofdays[1];
      }
      if(int_month=3) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[2] +=numberofdays[i];
        }
        sumofdays[2] +=int_day;
        passingdays=(double)sumofdays[2];
      }
      if(int_month=4) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[3] +=numberofdays[i];
        }
        sumofdays[3] +=int_day;
        passingdays=(double)sumofdays[3];
      }
      if(int_month=5) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[4] +=numberofdays[i];
        }
        sumofdays[4] +=int_day;
        passingdays=(double)sumofdays[4];
      }
      if(int_month=6) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[5] +=numberofdays[i];
        }
        sumofdays[5] +=int_day;
        passingdays=(double)sumofdays[5];
      }
      if(int_month=7) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[6] +=numberofdays[i];
        }
        sumofdays[6] +=int_day;
        passingdays=(double)sumofdays[6];
      }
      if(int_month=8) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[7] +=numberofdays[i];
        }
        sumofdays[7] +=int_day;
        passingdays=(double)sumofdays[7];
      }
      if(int_month=9) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[8] +=numberofdays[i];
        }
        sumofdays[8] +=int_day;
        passingdays=(double)sumofdays[8];
      }
      if(int_month=10) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[9] +=numberofdays[i];
        }
        sumofdays[9] +=int_day;
        passingdays=(double)sumofdays[9];
      }
      if(int_month=11) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[10] +=numberofdays[i];
        }
        sumofdays[10] +=int_day;
        passingdays=(double)sumofdays[10];
      }
      if(int_month=12) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[11] +=numberofdays[i];
        }
        sumofdays[11] +=int_day;
        passingdays=(double)sumofdays[11];
      }
   }
   if(year==2022)
    {
      for(int k=0;k<12;k++)
      {
         numberofdays[k]= pgm_read_word_near(dayofmonth2022 + k);
      }
      
      if(int_month=1) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[0] +=numberofdays[i];
        }
        sumofdays[0] +=int_day;
        passingdays=(double)sumofdays[0];
      }
      if(int_month=2) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[1] +=numberofdays[i];
        }
        sumofdays[1] +=int_day;
        passingdays=(double)sumofdays[1];
      }
      if(int_month=3) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[2] +=numberofdays[i];
        }
        sumofdays[2] +=int_day;
        passingdays=(double)sumofdays[2];
      }
      if(int_month=4) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[3] +=numberofdays[i];
        }
        sumofdays[3] +=int_day;
        passingdays=(double)sumofdays[3];
      }
      if(int_month=5) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[4] +=numberofdays[i];
        }
        sumofdays[4] +=int_day;
        passingdays=(double)sumofdays[4];
      }
      if(int_month=6) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[5] +=numberofdays[i];
        }
        sumofdays[5] +=int_day;
        passingdays=(double)sumofdays[5];
      }
      if(int_month=7) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[6] +=numberofdays[i];
        }
        sumofdays[6] +=int_day;
        passingdays=(double)sumofdays[6];
      }
      if(int_month=8) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[7] +=numberofdays[i];
        }
        sumofdays[7] +=int_day;
        passingdays=(double)sumofdays[7];
      }
      if(int_month=9) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[8] +=numberofdays[i];
        }
        sumofdays[8] +=int_day;
        passingdays=(double)sumofdays[8];
      }
      if(int_month=10) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[9] +=numberofdays[i];
        }
        sumofdays[9] +=int_day;
        passingdays=(double)sumofdays[9];
      }
      if(int_month=11) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[10] +=numberofdays[i];
        }
        sumofdays[10] +=int_day;
        passingdays=(double)sumofdays[10];
      }
      if(int_month=12) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[11] +=numberofdays[i];
        }
        sumofdays[11] +=int_day;
        passingdays=(double)sumofdays[11];
      }
   }
   if(year==2023)
    {
      for(int k=0;k<12;k++)
      {
         numberofdays[k]= pgm_read_word_near(dayofmonth2023 + k);
      }
      
      if(int_month=1) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[0] +=numberofdays[i];
        }
        sumofdays[0] +=int_day;
        passingdays=(double)sumofdays[0];
      }
      if(int_month=2) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[1] +=numberofdays[i];
        }
        sumofdays[1] +=int_day;
        passingdays=(double)sumofdays[1];
      }
      if(int_month=3) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[2] +=numberofdays[i];
        }
        sumofdays[2] +=int_day;
        passingdays=(double)sumofdays[2];
      }
      if(int_month=4) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[3] +=numberofdays[i];
        }
        sumofdays[3] +=int_day;
        passingdays=(double)sumofdays[3];
      }
      if(int_month=5) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[4] +=numberofdays[i];
        }
        sumofdays[4] +=int_day;
        passingdays=(double)sumofdays[4];
      }
      if(int_month=6) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[5] +=numberofdays[i];
        }
        sumofdays[5] +=int_day;
        passingdays=(double)sumofdays[5];
      }
      if(int_month=7) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[6] +=numberofdays[i];
        }
        sumofdays[6] +=int_day;
        passingdays=(double)sumofdays[6];
      }
      if(int_month=8) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[7] +=numberofdays[i];
        }
        sumofdays[7] +=int_day;
        passingdays=(double)sumofdays[7];
      }
      if(int_month=9) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[8] +=numberofdays[i];
        }
        sumofdays[8] +=int_day;
        passingdays=(double)sumofdays[8];
      }
      if(int_month=10) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[9] +=numberofdays[i];
        }
        sumofdays[9] +=int_day;
        passingdays=(double)sumofdays[9];
      }
      if(int_month=11) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[10] +=numberofdays[i];
        }
        sumofdays[10] +=int_day;
        passingdays=(double)sumofdays[10];
      }
      if(int_month=12) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[11] +=numberofdays[i];
        }
        sumofdays[11] +=int_day;
        passingdays=(double)sumofdays[11];
      }
   }
   if(year==2024)
    {
      for(int k=0;k<12;k++)
      {
         numberofdays[k]= pgm_read_word_near(dayofmonth2024 + k);
      }
      
      if(int_month=1) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[0] +=numberofdays[i];
        }
        sumofdays[0] +=int_day;
        passingdays=(double)sumofdays[0];
      }
      if(int_month=2) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[1] +=numberofdays[i];
        }
        sumofdays[1] +=int_day;
        passingdays=(double)sumofdays[1];
      }
      if(int_month=3) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[2] +=numberofdays[i];
        }
        sumofdays[2] +=int_day;
        passingdays=(double)sumofdays[2];
      }
      if(int_month=4) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[3] +=numberofdays[i];
        }
        sumofdays[3] +=int_day;
        passingdays=(double)sumofdays[3];
      }
      if(int_month=5) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[4] +=numberofdays[i];
        }
        sumofdays[4] +=int_day;
        passingdays=(double)sumofdays[4];
      }
      if(int_month=6) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[5] +=numberofdays[i];
        }
        sumofdays[5] +=int_day;
        passingdays=(double)sumofdays[5];
      }
      if(int_month=7) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[6] +=numberofdays[i];
        }
        sumofdays[6] +=int_day;
        passingdays=(double)sumofdays[6];
      }
      if(int_month=8) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[7] +=numberofdays[i];
        }
        sumofdays[7] +=int_day;
        passingdays=(double)sumofdays[7];
      }
      if(int_month=9) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[8] +=numberofdays[i];
        }
        sumofdays[8] +=int_day;
        passingdays=(double)sumofdays[8];
      }
      if(int_month=10) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[9] +=numberofdays[i];
        }
        sumofdays[9] +=int_day;
        passingdays=(double)sumofdays[9];
      }
      if(int_month=11) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[10] +=numberofdays[i];
        }
        sumofdays[10] +=int_day;
        passingdays=(double)sumofdays[10];
      }
      if(int_month=12) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[11] +=numberofdays[i];
        }
        sumofdays[11] +=int_day;
        passingdays=(double)sumofdays[11];
      }
   }
   if(year==2025)
    {
      for(int k=0;k<12;k++)
      {
         numberofdays[k]= pgm_read_word_near(dayofmonth2025 + k);
      }
      
      if(int_month=1) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[0] +=numberofdays[i];
        }
        sumofdays[0] +=int_day;
        passingdays=(double)sumofdays[0];
      }
      if(int_month=2) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[1] +=numberofdays[i];
        }
        sumofdays[1] +=int_day;
        passingdays=(double)sumofdays[1];
      }
      if(int_month=3) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[2] +=numberofdays[i];
        }
        sumofdays[2] +=int_day;
        passingdays=(double)sumofdays[2];
      }
      if(int_month=4) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[3] +=numberofdays[i];
        }
        sumofdays[3] +=int_day;
        passingdays=(double)sumofdays[3];
      }
      if(int_month=5) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[4] +=numberofdays[i];
        }
        sumofdays[4] +=int_day;
        passingdays=(double)sumofdays[4];
      }
      if(int_month=6) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[5] +=numberofdays[i];
        }
        sumofdays[5] +=int_day;
        passingdays=(double)sumofdays[5];
      }
      if(int_month=7) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[6] +=numberofdays[i];
        }
        sumofdays[6] +=int_day;
        passingdays=(double)sumofdays[6];
      }
      if(int_month=8) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[7] +=numberofdays[i];
        }
        sumofdays[7] +=int_day;
        passingdays=(double)sumofdays[7];
      }
      if(int_month=9) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[8] +=numberofdays[i];
        }
        sumofdays[8] +=int_day;
        passingdays=(double)sumofdays[8];
      }
      if(int_month=10) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[9] +=numberofdays[i];
        }
        sumofdays[9] +=int_day;
        passingdays=(double)sumofdays[9];
      }
      if(int_month=11) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[10] +=numberofdays[i];
        }
        sumofdays[10] +=int_day;
        passingdays=(double)sumofdays[10];
      }
      if(int_month=12) 
      {
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays[11] +=numberofdays[i];
        }
        sumofdays[11] +=int_day;
        passingdays=(double)sumofdays[11];
      }
   }
}   
   
