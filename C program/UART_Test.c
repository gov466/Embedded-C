#include <stdio.h> //Standard C input Output Library
#include <unistd.h> //defines miscellaneous symbolic constants and types, and declares miscellaneous functions
#include <string.h> //C Library for various String Operations
#include <termios.h> // Contains the definitions used by the terminal I/O interfaces 

#include <sys/types.h> //definitions for types like size_t , ssize_t
#include <sys/stat.h> //header defines the structure of the data returned by the functions fstat(), lstat(), and stat(), give file size
#include <fcntl.h> // FIle control, Open, close


//Reference Link: https://electronics.trev.id.au/2018/02/09/get-uart-serial-ports-working-beaglebone-black/
 
 int main (void) // Main function
{
    int file, i; // Variable integers
    char receive[100]; // declare a char array for receiving data
    char buf[20]; // A buffer char array to store temporary data
    
    size_t nbytes; //size_t is an unsigned integer data type used for storing size
    ssize_t bytes_written; // //size_t is an signed integer data type used for storing size
	
	// /dev/ttyO4 is linked with UART4 Port of Beaglebone 
    if ((file = open("/dev/ttyO1", O_RDWR))<0) // Try opening file in Read Write mode
    {
		
        printf("UART: Failed to open the file.\n"); //A message Print
        return 0;
    }
    
    else
    {
		printf("UART: Started\n"); //A message Print
		
	}

    
    struct termios options; // the termios structure is vital
    tcgetattr(file, &options); // sets the parameters associated with file

    // Set up the communications options:
    // 9600 baud, 8-bit, enable receiver, no modem control lines
    options.c_cflag = B9600 | CS8 | CREAD | CLOCAL; //Setting Baud Rate and other Parameters
    options.c_iflag = IGNPAR | ICRNL; // ignore partity errors, CR -> newline
    tcflush(file, TCIFLUSH); // discard file information not transmitted
    tcsetattr(file, TCSANOW, &options); // changes occur immmediately


	sleep(1);
	memset(buf, 0, sizeof(buf)); 
    strcpy(buf, "TEST COMMAND"); // Copy a string in buf char array
    nbytes = strlen(buf); // Store size of buf array in nbytes
    
    bytes_written = write(file, buf, nbytes); // Sending message to GSM Module
    
    sleep(3);
	int bytes_read = 0;
	
	bytes_read = read(file,&receive,100); // Read the incoming Message from GSM Module
	Read the file and store the data in receive , read 100 bytes max
	
	printf("\n\nBytes Received - %d",bytes_read); // Print how many bytes was received
	printf("\n");
	
	if(bytes_read > 1) //If no. of bytes are read is more than 1
	{
		for(i=0;i<bytes_read;i++) //a for loop to print data byte by byte
		{
			printf("%c",receive[i]); //print a byte of message from GSM Module
		}
		printf("\n-----------------------------------------\n\n"); //General Print

        sleep(2);
	}
	
	
	
  
  
    close(file); //Close the file at last
}
