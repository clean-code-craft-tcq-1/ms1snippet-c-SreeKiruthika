/************************************************************************************************************************/
/* This file contains the inclusions and definitions needed for sensor validation*/
/************************************************************************************************************************/
#include <math.h>

/***************DEFINES section *****************************/
#define TOLERANCE_SOC      0.05
#define TOLERANCE_CURRENT  0.1
#define NAN                sqrt(-1) 
#define NOISY              0
#define NOISE_FREE         1

/************************************************************/

/*******Global variables declaration*******/
enum SENSOR_TYPE {SOC, CURRENT, NUMSENSOR};

struct SensorProp_s
{
	char name[10];
	double tolerance;
}SensorProperties[NUMSENSOR];

extern const SensorProperties[SOC] = {"SoC" , TOLERANCE_SOC};
extern const SensorProperties[CURRENT] = {"Current" , TOLERANCE_CURRENT};

/*****************************************/

/**************Function prototype section**********************/

int IsWithinTolerance(double value, double nextValue, double tolerance);

int validateSensorReadings(double* sensorReading, int numOfReadings, struct SensorProp_s Sensor);

/************************************************************/