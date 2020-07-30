/*
 * ADXL345Accelerometer.h
 *
 *  Created on: Jul. 29, 2020
 *      Author: govind
 */

#ifndef ADXL345ACCELEROMETER_H_
#define ADXL345ACCELEROMETER_H_

#define ADXL345_POWER_CTL		0x2D	// R/W Power saving features control

/* ADXL345_POWER_CTL Bits */
#define ADXL345_PWRCTL_LINK			(1 << 5)
#define ADXL345_PWRCTL_AUTO_SLEEP	(1 << 4)
#define ADXL345_PWRCTL_MEASURE		(1 << 3)
#define ADXL345_PWRCTL_SLEEP		(1 << 2)
#define ADXL345_PWRCTL_WAKEUP(x)	((x) & 0x3)

#define MAX_BUS 				64

class ADXL345Accelerometer {

private:
	int i2cBus, i2cAddress,i2cHandle;
	char namebuf[MAX_BUS];

	signed int accelerationX, accelerationY, accelerationZ;
	signed int roll,pitch;
	signed short rawData_X, rawData_Y, rawData_Z;
	int opResult, tenBitAddress;

	float deviceTemperature;

public:
	ADXL345Accelerometer(int bus, int address);
	int initAccelerometer();
	unsigned int getAccelerometer_ID();
	void SetPowerMode(unsigned char );
	int getAccelerationData();
	signed int getAcceleration_X();
	signed int getAcceleration_Y();
	signed int getAcceleration_Z();
	signed int getPitch();
	signed int getRoll();

	virtual ~ADXL345Accelerometer();
};




#endif /* ADXL345ACCELEROMETER_H_ */
