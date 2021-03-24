#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sensor-validate.h"

struct SensorProp_s SensorProperties[NUMSENSOR] = {
												   {"SoC" , TOLERANCE_SOC},
												   {"Curent" , TOLERANCE_CURRENT}};

/* Test for noisy SOC sensor*/
TEST_CASE("reports error when soc jumps abruptly") 
{
  double socReadings[] = {0.0, 0.01, 0.5, 0.51};
  int numOfSocReadings = NumOfReadingsFromSensor(socReadings);
  REQUIRE(validateSensorReadings(socReadings, numOfSocReadings,SensorProperties[SOC]) == NOISY);
}

/* Test for noise free SOC sensor*/
TEST_CASE("reports error when soc jumps abruptly,,both increase and decrease")
{
  double socReadings[] = {0.08, 0.05, 0.1, 0.06, 0.09};
  int numOfSocReadings = NumOfReadingsFromSensor(socReadings);
  printf("\n%d", numOfSocReadings);
  REQUIRE(validateSensorReadings(socReadings, numOfSocReadings,SensorProperties[SOC]) == NOISE_FREE);
}

/* Test for noisy SOC sensor*/
TEST_CASE("reports error when soc drops abruptly") 
{
  double socReadings[] = {1, 1.04, 0.99, 1.02};
  int numOfSocReadings = NumOfReadingsFromSensor(socReadings);
  REQUIRE(validateSensorReadings(socReadings, numOfSocReadings,SensorProperties[SOC]) == NOISY);
}

/* Test for no readings from SOC sensor*/
TEST_CASE("reports error no sensor data is read") {
  double *socReadings = NULL;
  int numOfSocReadings = NumOfReadingsFromSensor(socReadings) ;
  printf("\n%d", numOfSocReadings);
  REQUIRE(validateSensorReadings(socReadings, numOfSocReadings,SensorProperties[SOC]) == INVALID_DATA);
}
/* Test for noisy Current sensor*/
TEST_CASE("reports error when current jumps abruptly") {
  double currentReadings[] = {0.0, 0.02, 0.03, 0.33};
  int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
  REQUIRE(validateSensorReadings(currentReadings, numOfCurReadings,SensorProperties[CURRENT]) == 0);
}
