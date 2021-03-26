#include "sensor.h"

/****************************************************************************************
*Func desc : This function checks if the sensor readings is noise free, this function assumes valid data is received
*Param     : sensorReading - pointer to the array that holds the sensor readings  - double
             numOfReadings - Number of readings recorded from the sensor          - int  
			 Sensor        - structure which holds sensor details                 - struct SensorProp_s
*Return    : Returns the validated status of sensor readings
			 0 - Sensor is NOISY
			 1 - Sensor is NOISE_FREE
*****************************************************************************************/
int IsSensorNoiseFree(double* sensorReading, int numOfReadings, struct SensorProp_s Sensor) 
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

/****************************************************************************************
*Func desc : This function checks sensor validity based on the readings received from sensor
*Param     : sensorReading - pointer to the array that holds the sensor readings  - double
             numOfReadings - Number of readings recorded from the sensor          - int  
			 Sensor        - structure which holds sensor details                 - struct SensorProp_s
*Return    : Returns the validated status of sensor based readings
			 0 - NOISE
			 1 - Sensor readings are OK
*****************************************************************************************/
int validateSensorReadings(double* sensorReading, int numOfReadings, struct SensorProp_s Sensor)
{
	int retval;
	
	if(IsReadingsDataValid(sensorReading,numOfReadings)!=INVALID_DATA)
	{
		retval =  IsSensorNoiseFree(sensorReading,numOfReadings,Sensor);
	}
	else
	{
	   printf("\n%s sensor readings not available",Sensor.name);
	   retval = INVALID_DATA;
	}
	return retval;
}
	
