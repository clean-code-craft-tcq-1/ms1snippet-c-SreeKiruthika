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
	    for(int i = 0;i < (numOfReadings - 1);i++)
        {
          if(!IsWithinTolerance(sensorReading[i], sensorReading[i + 1], Sensor.tolerance)) 
	      {
	        printf("\n%s sensor is noisy, sudden jump detected between reading %d and %d" , Sensor.name,i+1,i+2);	
            return NOISY;
          }
		}  
		printf("\n%s sensor is noise-free" , Sensor.name);
        return NOISE_FREE;

}

int isDataValid(double* sensorReading, int numOfReadings)
{
	if ((numOfReadings == 0)||(sensorReading == NULL))
    {
       return INVALID_DATA;
    }
	return VALID_DATA;
}

int validateSensorBasedOnReadings(double* sensorReading, int numOfReadings, struct SensorProp_s Sensor)
{
	int retval;
	
	if(isDataValid(sensorReading,numOfReadings)!=INVALID_DATA)
	{
		retval =  validateSensorReadings(sensorReading,numOfReadings,Sensor);
	}
	else
	{
	   printf("\n%s sensor readings not available",Sensor.name);
	   retval = INVALID_DATA;
	}
	return retval;
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