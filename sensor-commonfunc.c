#include "sensor.h"

/****************************************************************************************
*Func desc : This function checks if the difference between the passed values are within tolerance 
*Param     : value     - first value    - double type
			 nextValue - second value   - double type
*Return    : Returns the status of tolerance check between the paased 2 parameters
			 0 - difference out of tolerance range
			 1 - difference within tolerance
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
*Func desc : This function checks if the data received is valid 
*Param     : dataBuffer - pointer to the array that holds the sensor readings  - double
             sizeofBuffer - Number of readings recorded from the sensor        - int 
*Return    : Returns the status of param limit check
			 255 - Invalid data
			 0   - Valid data
*****************************************************************************************/
int IsReadingsDataValid(double* dataBuffer, int sizeofBuffer)
{
	if ((sizeofBuffer == 0)||(dataBuffer == NULL))
    {
       return INVALID_DATA;
    }
	return VALID_DATA;
}
