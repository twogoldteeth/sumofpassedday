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
  Serial.begin(38400);
  Serial1.begin(GPSBaud);
  lcd.begin(16, 2);
}

void loop()
{
  
  gps_passingday(); 
       
}
void gps_passingday(void)
{
  while(Serial1.available()>0)
  {
       char data=Serial1.read();
       gps.encode(data);
       if(gps.location.isUpdated() && gps.altitude.isUpdated())
       {
          lat1=gps.location.lat();
          lon1=gps.location.lng();
          alt1=gps.altitude.meters();
          sat1=gps.satellites.value();
          year=gps.date.year();
          month=gps.date.month();
          day=gps.date.day();

          passingdays=passing_day();
           
          Serial.println(); 
          Serial.print("Passing_day= ");Serial.println(passingdays); 
          Serial.println(); 
    
          Serial.print("Latitude= ");Serial.println(lat1,6);
          Serial.print("Longitude= ");Serial.println(lon1,6);
          Serial.print("Altitude in meters= ");Serial.println(alt1);
          Serial.print("Number of satellites in use = ");Serial.println(sat1);
          Serial.print("Year = "); Serial.println(year);
          Serial.print("Month = "); Serial.println(month);
          Serial.print("Day = "); Serial.println(day);
           

          lcd.setCursor(0, 0);
          lcd.print(lat1,6);lcd.print(",");lcd.print(lon1);
          lcd.setCursor(0, 1);
          lcd.print("Passingdays=");lcd.print(" ");lcd.print(passingdays);
       }
    
   }
    
}

double passing_day(void)
{
    int int_year=(int)year;
    int int_month=(int)month;
    int int_day=(int)day;

    
    if(year==2021)
    {
     
      
      const int dayofmonth2021[12] = {31,28,31,30,31,30,31,31,30,31,30,31};    
     
      
      if(int_month== 1) 
      {
       
        double passing_days=0;
        int sumofdays=0;
        sumofdays = int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month== 2) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays += dayofmonth2021[i];
        }
        sumofdays += int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==3) 
      {
        
        double passing_days=0;
        int sumofdays=0;  
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2021[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==4) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2021[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==5) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2021[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==6) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2021[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==7) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2021[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==8) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2021[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==9) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2021[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==10) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2021[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==11) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2021[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==12) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2021[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
   }
    if(year==2022)
    {
     
      const int dayofmonth2022[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
           
            
      if(int_month== 1) 
      {
       
        double passing_days=0;
        int sumofdays=0;
        sumofdays = int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month== 2) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays += dayofmonth2022[i];
        }
        sumofdays += int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==3) 
      {
        
        double passing_days=0;
        int sumofdays=0;  
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2022[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==4) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2022[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==5) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2022[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==6) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2022[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==7) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2022[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==8) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2022[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==9) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2022[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==10) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2022[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==11) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2022[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==12) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2022[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
   }
    if(year==2023)
    {
     
      const int dayofmonth2023[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
           
      if(int_month== 1) 
      {
       
        double passing_days=0;
        int sumofdays=0;
        sumofdays = int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month== 2) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays += dayofmonth2023[i];
        }
        sumofdays += int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==3) 
      {
        
        double passing_days=0;
        int sumofdays=0;  
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2023[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==4) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2023[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==5) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2023[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==6) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2023[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==7) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2023[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==8) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2023[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==9) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2023[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==10) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2023[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==11) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2023[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==12) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2023[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
   }
    if(year==2024)
    {
     
      const int dayofmonth2024[12] = {31,29,31,30,31,30,31,31,30,31,30,31};;
           
      if(int_month== 1) 
      {
       
        double passing_days=0;
        int sumofdays=0;
        sumofdays = int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month== 2) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays += dayofmonth2024[i];
        }
        sumofdays += int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==3) 
      {
        
        double passing_days=0;
        int sumofdays=0;  
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2024[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==4) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2024[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==5) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2024[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==6) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2024[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==7) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2024[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==8) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2024[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==9) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2024[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==10) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2024[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==11) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2024[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==12) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2024[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
   }
    if(year==2025)
    {
     
      const int dayofmonth2025[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
           
      if(int_month== 1) 
      {
       
        double passing_days=0;
        int sumofdays=0;
        sumofdays = int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month== 2) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays += dayofmonth2025[i];
        }
        sumofdays += int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==3) 
      {
        
        double passing_days=0;
        int sumofdays=0;  
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2025[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==4) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2025[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==5) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2025[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==6) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2025[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==7) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2025[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==8) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2025[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==9) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2025[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==10) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2025[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==11) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2025[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
      if(int_month==12) 
      {
        double passing_days=0;
        int sumofdays=0; 
        for(int i=0;i<(int_month-1);i++)
        {
           sumofdays +=dayofmonth2025[i];
        }
        sumofdays +=int_day;
        passing_days=(double)sumofdays;
        return passing_days;
      }
   }
}   
