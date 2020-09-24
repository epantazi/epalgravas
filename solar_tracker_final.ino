#include <Servo.h>

Servo servohori;
int servoh = 90;
int servohLimitHigh = 90;
int servohLimitLow = 0;

Servo servoverti; 
int servov = 0; 
int servovLimitHigh = 180;
int servovLimitLow = 0;
//Pin fotoresistenze
int ldrtopl = 0; //top left 
int ldrtopr = 2; //top right 
int ldrbotl = 1; // bottom left 
int ldrbotr = 3; // bottom right 

 void setup () 
 {
  servohori.attach(10, 1000, 2000);
  servohori.write(0);
  servoverti.attach(9, 1000, 2200);
  servoverti.write(0);
  Serial.begin(9600);
  delay(500); 
 }

void loop()
{
  servoh = servohori.read();
  servov = servoverti.read();
  
  int topl = analogRead(ldrtopl);
  int topr = analogRead(ldrtopr);
  int botl = analogRead(ldrbotl);
  int botr = analogRead(ldrbotr);
  
  int avgtop = (topl + topr) ; //average of top 
  int avgbot = (botl + botr) ; //average of bottom 
  int avgleft = (topl + botl) ; //average of left 
  int avgright = (topr + botr) ; //average of right 

  if (avgtop < avgbot)
  {
    servoverti.write(servov +1);
    if (servov > servovLimitHigh) 
     { 
      servov = servovLimitHigh;
     }
    delay(10);
  }
  else if (avgbot < avgtop)
  {
    servoverti.write(servov -1);
    if (servov < servovLimitLow)
  {
    servov = servovLimitLow;
  }
    delay(10);
  }
  else 
  {
    servoverti.write(servov);
  }
  
  if (avgleft > avgright)
  {
    servohori.write(servoh +1);
    if (servoh > servohLimitHigh)
    {
    servoh = servohLimitHigh;
    }
    delay(10);
  }
  else if (avgright > avgleft)
  {
    servohori.write(servoh -1);
    if (servoh < servohLimitLow)
     {
     servoh = servohLimitLow;
     }
    delay(10);
  }
  else 
  {
    servohori.write(servoh);
  }
  delay(50);
}
