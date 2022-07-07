// NTC B3950 Thermistor
// the formula for temp in kelvin is
//                 1
// T = ----------------------------
//     1/To + (1/beta) * ln(Rt/Ro)
//
//https://github.com/e-tinkers/ntc-thermistor-with-arduino-and-esp32/blob/master/ntc_3950.ino
//https://github.com/e-tinkers/esp32-adc-calibrate/blob/master/examples/esp32_adc_lut_example.ino
// https://en.wikipedia.org/wiki/Thermistor
// ESP32 ADC non-liear issue
// https://www.esp32.com/viewtopic.php?t=1045
// https://github.com/espressif/esp-idf/issues/164
// https://docs.espressif.com/projects/esp-idf/en/latest/api-reference/peripherals/adc.html#adc-calibration
#define ONBOARD_LED  2
#define relay1 16
#define relay2 17
#include "ESP32Thermistor.h"
#define tbtn1 13
#define tbtn2 12
#define tbtn3 14

ESP32Thermistor thermistor(34,true);

int defaultTemp = 100; //100 = manual
int Auto = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ONBOARD_LED,OUTPUT);
  digitalWrite(ONBOARD_LED,LOW);
      pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);  
    digitalWrite(relay1, HIGH);
    digitalWrite(relay2, HIGH);
}
int touchSimple1(){
  float touch_sensor_value = touchRead(tbtn1);
  if (touchRead(tbtn1) < 40) 
  {
    delay (200);
    if (touchRead(tbtn1) < 40) return 1;
  }
  return 0;
}
int touchSimple2(){
  float touch_sensor_value = touchRead(tbtn2);
  if (touchRead(tbtn2) < 40) 
  {
    delay (200);
    if (touchRead(tbtn2) < 40) return 1;
  }
  return 0;
}
int touchSimple3(){
  float touch_sensor_value = touchRead(tbtn3);
  if (touchRead(tbtn3) < 40) 
  {
    delay (200);
    if (touchRead(tbtn3) < 40) return 1;
  }
  return 0;
}
void loop() {
  float thermistorTempC = thermistor.getTempC();
  Serial.println(thermistorTempC);
  delay(500);
  String defaultTempStr;
  if(Serial.available()){
        defaultTempStr = Serial.readStringUntil('\n');
        Serial.println("Remote Temp Set To " + defaultTempStr + "!");
        defaultTemp = defaultTempStr.toInt();
        Auto = 1;
        digitalWrite(ONBOARD_LED,HIGH);
    }
  Serial.print("defaultTemp: ");
  Serial.println(defaultTemp);
    if (touchSimple1())
  {
    Serial.println("Touch-1");
    digitalWrite(relay1,(!digitalRead(relay1)));
    Auto = 0;
    digitalWrite(ONBOARD_LED,LOW);
  }
    if (touchSimple2())
  {
    Serial.println("Touch-2");
    digitalWrite(relay2,(!digitalRead(relay2)));
    Auto = 0;
    digitalWrite(ONBOARD_LED,LOW);
  }
  if (touchSimple3())
  {
    if (defaultTemp !=100)
    {
      Auto = 1;
      digitalWrite(ONBOARD_LED,HIGH);
    }
  }
  if (Auto == 1 && defaultTemp !=100)
  {
    if (thermistorTempC > defaultTemp && digitalRead(relay2))
    {
      digitalWrite(relay1,LOW);
      delay(1000);
      digitalWrite(relay2,LOW);
    }
    if (thermistorTempC < defaultTemp && (!digitalRead(relay2)))
    {
      digitalWrite(relay1,HIGH);
      digitalWrite(relay2,HIGH);
    }
  }


}
