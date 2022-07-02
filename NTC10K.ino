// NTC B3950 Thermistor
// the formula for temp in kelvin is
//                 1
// T = ----------------------------
//     1/To + (1/beta) * ln(Rt/Ro)
//
//https://github.com/e-tinkers/esp32-adc-calibrate/blob/master/examples/esp32_adc_lut_example.ino
// https://en.wikipedia.org/wiki/Thermistor

// ESP32 ADC non-liear issue
// https://www.esp32.com/viewtopic.php?t=1045
// https://github.com/espressif/esp-idf/issues/164
// https://docs.espressif.com/projects/esp-idf/en/latest/api-reference/peripherals/adc.html#adc-calibration

#include "ESP32Thermistor.h"

ESP32Thermistor thermistor(34);

void setup() {
  Serial.begin(115200);
}

void loop() {
  float thermistorTempC = thermistor.getTempC();
Serial.println(thermistorTempC);

  delay(2000);
}
