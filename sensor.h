/************************************************************************************************************************/
/* This file contains the inclusions and definitions needed for sensor validation*/
/************************************************************************************************************************/

#include <stdio.h>
#include <math.h>

/***************DEFINES section ******************************/
#define TOLERANCE_SOC      0.05
#define TOLERANCE_CURRENT  0.1
#define INVALID_DATA       255 
#define VALID_DATA         0
#define NOISY              0
#define NOISE_FREE         1

/*************************************************************/

/***************** Global variables declaration***************/
enum SENSOR_TYPE {SOC, CURRENT, NUMSENSOR};

struct SensorProp_s
{
	char name[10];
	double tolerance;
};

/**************************************************************/

/**************Function prototype section**********************/

int IsWithinTolerance(double value, double nextValue, double tolerance);

int IsSensorReadingsNoiseFree(double* sensorReading, int numOfReadings, struct SensorProp_s Sensor);

int validateSensorReadings(double* sensorReading, int numOfReadings, struct SensorProp_s Sensor);

int IsReadingsDataValid(double* dataBuffer, int sizeofBuffer);

/**************************************************************/