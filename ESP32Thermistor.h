/** \addtogroup Thermistor
    @{
*/


#ifndef ESP32THERMISTOR_H
#define ESP32THERMISTOR_H
#include <Arduino.h>

#define ReadSamples 5 // how many samples to take and average, more takes longer but is more 'smooth'
#define R1 10000.0//10000  // Ro: defined resistance at 25 degrees C    
#define To 298.15 // T0: temp. for nominal resistance (almost always 25 C)
#define Beta 3950.0//3977 // B: The beta coefficient of the thermistor (usually 3000-4000)
#define Ro 10000.0 // the value of the 'other' resistor
#define adcMax 4095.0 // ADC resolution 12-bit (0-4095)
#define Vs 3.3        // supply voltage


class ESP32Thermistor {
  public:
    ESP32Thermistor(const int pin);
    //Get avreaged temeprature measurement in Celsius
    float getTempC(byte calReadings = ReadSamples);
    //Get avreaged temeprature measurement in Fahrenheit
    float getTempF(byte calReadings = ReadSamples);
};

#endif //THERMISTOR
/** @}*/
