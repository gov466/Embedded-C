#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>

void main() 
{
	while(1)
	{
	// Creating I2C-2 bus_
	int file;
	char *bus_ = "/dev/i2c-2";
	if ((file = open(bus_, O_RDWR)) < 0) 
	{
		printf("Cannot open bus_. \n");
		exit(1);
	}
	//  I2C device, Address of ADXL345 is 0x53(83)
	ioctl(file, I2C_SLAVE, 0x53);

	// Selecting Bandwidth_rate_register(0x2C)
	//in_Normal_mode, Output_data_rate = 100 Hz(0x0A)
	char config[2]={0};
	config[0] = 0x2C;
	config[1] = 0x0A;
	write(file, config, 2);
	// Select PCR(Power_control_register)(0x2D)
	// Auto-sleep_disable(0x08)
	config[0] = 0x2D;
	config[1] = 0x08;
	write(file, config, 2);
	// Select DFR(Data_format_register)(0x31)
	// Self_test_disabled, 4-wire_interface, Full_resolution, range = +/-2g(0x08)
	config[0] = 0x31;
	config[1] = 0x08;
	write(file, config, 2);
	sleep(1);

	// Reading data(6bytes) from_register(0x32)
	// x_Acc_lsb, x_Acc_msb, y_Acc_lsb, y_Acc_msb, z_Acc_lsb, z_Acc_msb
	char reg[1] = {0x32};
	write(file, reg, 1);
	char data[6] ={0};
	if(read(file, data, 6) != 6)
	{
		printf("Incorrect : I/O Incorrect \n");
		exit(1);
	}
	else
	{
		// Convert the data to 10-bits
		int x_Acc = ((data[1] & 0x03) * 256 + (data[0] & 0xFF));
		if(x_Acc > 511)
		{
			x_Acc -= 1024;
		}

		int y_Acc = ((data[3] & 0x03) * 256 + (data[2] & 0xFF));
		if(y_Acc > 511)
		{
			y_Acc -= 1024;
		}

		int z_Acc = ((data[5] & 0x03) * 256 + (data[4] & 0xFF));
		if(z_Acc > 511)
		{
			z_Acc -= 1024;
		}

		// Output data to screen
		printf("Accelerometer reading \n ");
		printf("	 X-Axis = %d \n", x_Acc);
		printf(" 	 Y-Axis = %d \n", y_Acc);
		printf("	 Z-Axis = %d \n", z_Acc);
	}
	}
}
