/**
*	使用SHT3X 模块测试温湿度信息	www.lingzhilab.com
*/

#include "HTU3X.h"

#define LED1	PA8
 
//Create an instance of the object
HTU3X myHumidity;

void setup()
{
  Serial.begin(9600);
  Serial.println("HTU21D Example!");

	pinMode(LED1, OUTPUT);

  myHumidity.begin();
}

void loop()
{
	digitalWrite(LED1, HIGH);
	delay(500);
	digitalWrite(LED1, LOW);
	
  float humd, temp;
  myHumidity.readTempAndHumi(&temp, &humd);

  Serial.print("时间:");
  Serial.print(millis());
  Serial.print(" 温度:");
  Serial.print(temp, 1);
  Serial.print(" °C");
  Serial.print(" 湿度:"); 
  Serial.print(humd, 1);
  Serial.print("%");

  Serial.println();
  delay(1000);
}