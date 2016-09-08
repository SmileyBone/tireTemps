/*************************************************** 
  This is a library example for the MLX90614 Temp Sensor

  Designed specifically to work with the MLX90614 sensors in the
  adafruit shop
  ----> https://www.adafruit.com/products/1748
  ----> https://www.adafruit.com/products/1749

  These sensors use I2C to communicate, 2 pins are required to  
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#define INNER_SENSOR_ADDR 0x11
#define MIDDLE_SENSOR_ADDR 0x22
#define OUTTER_SENSOR_ADDR 0x33

#include <Wire.h>
#include <Adafruit_MLX90614.h>

//for racing setup
Adafruit_MLX90614 inner = Adafruit_MLX90614(INNER_SENSOR_ADDR);
Adafruit_MLX90614 middle = Adafruit_MLX90614(MIDDLE_SENSOR_ADDR);//add MIDDLE_SENSOR_ADDR once sensor is programmed
Adafruit_MLX90614 outer = Adafruit_MLX90614(OUTTER_SENSOR_ADDR);

void setup() {
  Serial.begin(115200);
  
  inner.begin();
  middle.begin();
  outer.begin();
}

unsigned long start_time = 0;
unsigned long t = 0;

uint16_t data[6];

void loop() {  
  
  if(millis() % 100 == 0){
    //start_time = micros();

    inner.readRawTemps(data);
    middle.readRawTemps(data + 2);
    outer.readRawTemps(data + 4);

    //t = micros() - start_time;
    
    for(int i=0;i<6;i++){
      Serial.print(data[i]);
      if(i != 5){
        Serial.print(", ");
      }
      else{
        Serial.println();
      }
    }

    //t = micros() - start_time;
    //Serial.print(t / 1000.0);
    //Serial.println(" ms");
  }
}
