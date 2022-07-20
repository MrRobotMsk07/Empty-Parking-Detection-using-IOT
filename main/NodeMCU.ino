#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>
#include <SimpleTimer.h>
 
char auth[] = "_3ZpaOjgQ45_vCssUHKHl50CM-N0_9y0";
 
char ssid[] = "#F SOCIETY";
char pass[] = "(&^&(#&#$^";
 
SimpleTimer timer;
 
String myString;
char rdata;
 
int firstVal, secondVal,thirdVal; // sensors 
int led1,led2,led3,led4,led5,led6;

void myTimerEvent()
{
  Blynk.virtualWrite(V1, millis() / 1000);
}
 
 
 
void setup()
{
  Serial.begin(9600);
 
  Blynk.begin(auth, ssid, pass);
 
    timer.setInterval(1000L,sensorvalue1); 
    timer.setInterval(1000L,sensorvalue2); 
    timer.setInterval(1000L,sensorvalue3);
    timer.setInterval(1000L,sensorvalue4);
    timer.setInterval(1000L,sensorvalue5);
    timer.setInterval(1000L,sensorvalue6);
}
 
void loop()
{
   if (Serial.available() == 0 ) 
   {
  Blynk.run();
  timer.run();
   }
   
  if (Serial.available() > 0 ) 
  {
    rdata = Serial.read(); 
    myString = myString+ rdata;
    if( rdata == '\n')
    {
     Serial.println(myString);
String l = getValue(myString, ',', 0);
String m = getValue(myString, ',', 1);
String n = getValue(myString, ',', 2);
String o = getValue(myString, ',', 3);
String p = getValue(myString, ',', 4);
String q = getValue(myString, ',', 5);
 
 
led1 = l.toInt();
led2 = m.toInt();
led3 = n.toInt();
led4 = o.toInt();
led5 = p.toInt();
led6 = q.toInt();
 
  myString = "";
    }
  }
 
}
 
void sensorvalue1()
{
int sdata = led1;

  Blynk.virtualWrite(V10, sdata);
 
}
void sensorvalue2()
{
int sdata = led2;
 
  Blynk.virtualWrite(V11, sdata);
 
}
 
void sensorvalue3()
{
int sdata = led3;

  Blynk.virtualWrite(V12, sdata);
 
}
 
void sensorvalue4()
{
int sdata = led4;

  Blynk.virtualWrite(V13, sdata);
 
}
 
void sensorvalue5()
{
int sdata = led5;

  Blynk.virtualWrite(V14, sdata);
 
}
 
void sensorvalue6()
{
int sdata = led6;

  Blynk.virtualWrite(V15, sdata);
 
}
 
String getValue(String data, char separator, int index)
{
    int found = 0;
    int strIndex[] = { 0, -1 };
    int maxIndex = data.length() - 1;
 
    for (int i = 0; i <= maxIndex && found <= index; i++) {
        if (data.charAt(i) == separator || i == maxIndex) {
            found++;
            strIndex[0] = strIndex[1] + 1;
            strIndex[1] = (i == maxIndex) ? i+1 : i;
        }
    }
    return found > index ? data.substring(strIndex[0], strIndex[1]) : "";
}