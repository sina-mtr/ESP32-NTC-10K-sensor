/** \addtogroup Thermistor
    @{
*/


#ifndef ESP32THERMISTOR_H
#define ESP32THERMISTOR_H
#include <Arduino.h>

#define ReadSamples 5 // how many samples to take and average, more takes longer but is more 'smooth'
#define R1 10000.0    //10000  // voltage divider resistor value    
#define To 298.15     // T0: temp. for nominal resistance (almost always 25 C)
#define Beta 3950.0   // or 3977.0. The beta coefficient of the thermistor (usually 3000-4000)
#define Ro 10000.0    // Ro: defined resistance at 25 degrees C
#define adcMax 4095.0 // ADC resolution 12-bit (0-4095)
#define Vs 3.3        // supply voltage
//#define reverse 1     //put thermistor as R1 or R2 in this: Vout = Vs * R1 / (R1 + R2)


class ESP32Thermistor {
  public:
    ESP32Thermistor(const int pin, const bool reverse);
    //Get avreaged temeprature measurement in Celsius
    float getTempC(byte calReadings = ReadSamples);
    //Get avreaged temeprature measurement in Fahrenheit
    float getTempF(byte calReadings = ReadSamples);
};

#endif //THERMISTOR
/** @}*/
