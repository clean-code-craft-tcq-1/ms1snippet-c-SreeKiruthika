#include "sensor-validate.h"

/****************************************************************************************
*Func desc : This function checks if the consecutive sensor readings are within tolerance 
*Param     : value - The measured battery parameter value, whole limits are to be verified - float type
*Return    : Returns the status of param limit check
			 0 - Sensor readings not within tolerance
			 1 - Sensor readings within tolerance
*****************************************************************************************/
int IsWithinTolerance(double value, double nextValue, double tolerance) 
{
  if(fabs(nextValue - value) > tolerance)
  {
    return 0;
  }
  return 1;
}

/****************************************************************************************
*Func desc : This function checks if the sensor is faulty based on the sensor readings
*Param     : sensorReading - pointer to the array that holds the sensor readings  - double
             numOfReadings - Number of readings recorded from the sensor          - int  
			 Sensor        - structure which holds sensor details                 - struct SensorProp_s
*Return    : Returns the validated status of sensor readings
			 0 - Sensor readings are NOT OK
			 1 - Sensor readings are OK
*****************************************************************************************/
int validateSensorReadings(double* sensorReading, int numOfReadings, struct SensorProp_s Sensor) 
{
    if ((numOfReadings == 0)||(sensorReading == NULL))
    {
       printf("%s sensor readings not available",Sensor.name);
	   return INVALID_DATA;
    }
    else
    {  
       int i = 0;
  
        while(i < (numOfReadings - 1))
        {
          if(!IsWithinTolerance(sensorReading[i], sensorReading[i + 1], Sensor.tolerance)) 
	      {
	        printf("%s sensor is noisy" , Sensor.name);	
            return NOISY;
          }
	      i++;
		}  
		printf("%s sensor is noise-free" , Sensor.name);
        return NOISE_FREE;
    }
  
}


int NumOfReadingsFromSensor(double readingsBuffer[])
{
	if (readingsBuffer == NULL)
	{
		return 0;
	}
	else
	{
	  return (sizeof(readingsBuffer) / sizeof(readingsBuffer[0]));
	}
}