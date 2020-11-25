/*
 * bbthingspeak.c
 *
 *  Created on: Nov. 23, 2020
 *      Author: govind
 */

#include <stdio.h> //Standard C input Output Library
#include <unistd.h> //defines miscellaneous symbolic constants and types, and declares miscellaneous functions
#include <string.h> //C Library for various String Operations
#include <termios.h> // Contains the definitions used by the terminal I/O interfaces
#include<time.h>
#include <sys/types.h> //definitions for types like size_t , ssize_t
#include <sys/stat.h> //header defines the structure of the data returned by the functions fstat(), lstat(), and stat(), give file size
#include <fcntl.h> // FIle control, Open, close

#define BAUDRATE B9600

int file1, i; // Variable integers
int speed = 0;
int threshold = 60;

int nbytes;
int bytes_written;
char buf[100]; // A buffer char array to store temporary data
//Function Declaration

void delay(unsigned int mseconds);

void setUART1();

//https://github.com/xanthium-enterprises/Serial-Port-Programming-on-Linux/blob/master/USB2SERIAL_Read/Reciever%20(PC%20Side)/SerialPort_read.c

int main(void) // Main function
{

	// /dev/ttyO1 is linked with UART1 Port of Beaglebone
	if ((file1 = open("/dev/ttyO1", O_RDWR | O_NOCTTY | O_NONBLOCK)) < 0) // Try opening file in Read Write mode
			{
		printf("UART1: Failed to open the file.\n"); //A message Print
		return 0;
	}

	setUART1();

	while (1) {

		delay(1000);
		if (speed > 0) {
			printf("Speed : %d\n", speed);

			if (speed > threshold) {

				printf("Sending data to ESP\n\n\n");
				memset(buf, 0, sizeof(buf));
				strcpy(buf, "1"); // Copy a string in buf char array
				nbytes = strlen(buf); // Store size of buf array in nbytes
				bytes_written = write(file1, buf, nbytes); // Sending message to ESP Module

			}

			speed = 0;
		}

	}

	printf("\n Done \n");

	close(file1); //Close the file at last
}

void delay(unsigned int mseconds) {
	clock_t goal = mseconds * 1000 + clock();
	while (goal > clock())
		;
}

void setUART1() {
	struct termios newtio1;
	/* set new port settings for canonical input processing */
	newtio1.c_cflag = BAUDRATE | CRTSCTS | CS8 | CLOCAL | CREAD;
	newtio1.c_iflag = IGNPAR | ICRNL;
	newtio1.c_oflag = 0;
	newtio1.c_lflag = ICANON;
	newtio1.c_cc[VMIN] = 0;
	newtio1.c_cc[VTIME] = 1;
	tcflush(file1, TCIFLUSH);
	tcsetattr(file1, TCSANOW, &newtio1);
	tcflush(file1, TCIOFLUSH);

}

