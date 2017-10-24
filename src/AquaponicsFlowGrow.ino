/*
 * Project AquaponicsFlowGrow
 * Description:
 * Author:
 * Date:
 */
 // This #include statement was automatically added by the Particle IDE.
 #include "Temperature.h"

 // This #include statement was automatically added by the Particle IDE.
 #include <OneWire.h>

 OneWire ds = OneWire(D4);  // 1-wire signal on pin D4

 unsigned long lastUpdate = 0;

 //float lastTemp;

 //photoresistor
 int photoresistor = A0;
 int power = A5; //other end of resistor
 int analogvalue;

 void setup() {
   Serial.begin(9600);
   // Set up 'power' pins, comment out if not used!
   //pinMode(D3, OUTPUT);
   //pinMode(D5, OUTPUT);
   //digitalWrite(D3, LOW);
   //digitalWrite(D5, HIGH);

   //photoresistor power setup
   pinMode(photoresistor, INPUT);
   pinMode(power,OUTPUT);

   digitalWrite(power, HIGH);

   Particle.variable("analogvalue", &analogvalue, INT);



 }

 // up to here, it is the same as the address scanner
 // we need a few more variables for this example

 void loop(void) {

   String fahrenheit = getTemperature(ds);
   //photoresistor reading
   analogvalue = analogRead(photoresistor);
   String light = String(analogvalue);

   Serial.print(" Light = ");
   Serial.print(light);

   Particle.publish("light", light, PRIVATE);
   delay(100);

   // now that we have the readings, we can publish them to the cloud
   String temperature = String(fahrenheit); // store temp in "temperature" string
   Particle.publish("temperature", temperature, PRIVATE); // publish to cloud
   delay(5000); // 5 second delay
 }
