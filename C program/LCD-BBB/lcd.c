/*
 * lcd.c
 *
 *  Created on: Nov. 2, 2020
 *      Author: govind
 */
#include <stdio.h> //standard input /output
#include <stdlib.h> //standard library
#include <unistd.h> //unix standard
#include <linux/i2c-dev.h>  //header file to control i2c devices from user space
#include <fcntl.h>  //file control operations
#include <sys/ioctl.h>   //input -output control


#define I2C_BUS    "/dev/i2c-2" // I2C bus device on a Beaglebone Black 
#define I2C_ADDR    0x27        // I2C slave address for the LCD module  

int i2cFile;  
int cursor_pos;  
  
  
void i2c_start() //Function to start i2c communication
{  
   if((i2cFile = open(I2C_BUS, O_RDWR)) < 0) 
   {  
      printf("Error failed to open I2C bus [%s].\n", I2C_BUS);  
      exit(-1);  
   }  
   // set the I2C slave address for all subsequent I2C device transfers  
   if (ioctl(i2cFile, I2C_SLAVE, I2C_ADDR) < 0) 
   {  
      printf("Error failed to set I2C address [%s].\n", I2C_ADDR);  
      exit(-1);  
   }  
}  
  
  
  
void i2c_send_byte(unsigned char data) //Send a byte of data via i2c 
{  
   unsigned char byte[1];  
   byte[0] = data;  
   write(i2cFile, byte, sizeof(byte));   
   /* -------------------------------------------------------------------- * 
    * Below wait creates 1msec delay, needed by display to catch commands  * 
    * -------------------------------------------------------------------- */  
   usleep(1000);  
}  
  
  
void clear_display()  //Function to clear Display
{  
   /* -------------------------------------------------------------------- * 
    * Display clear, cursor home                                           * 
    * -------------------------------------------------------------------- */  
   usleep(40);                // wait 40usec  
   i2c_send_byte(0b00000100); //  
   i2c_send_byte(0b00000000); // D7-D4=0  
   i2c_send_byte(0b00010100); //  
   i2c_send_byte(0b00010000); // D0=display_clear  
  
}

void display_on()
{
   /* -------------------------------------------------------------------- * 
    * Turn on the display                                                  * 
    * -------------------------------------------------------------------- */  
   usleep(40);                // wait 40usec  
   i2c_send_byte(0b00001100); //  
   i2c_send_byte(0b00001000); // D7-D4=0  
   i2c_send_byte(0b11101100); //  
   i2c_send_byte(0b11101000); // D3=1 D2=display_on, D1=cursor_on, D0=cursor_blink  
   cursor_pos =1 ;  
}   
  
  
void go_to(int line, char position)  //Function to move cursor of lcd
{  
	if(line==1)  position = 0x80+position;  

	else if(line==2)  position = 0xC0+position;  
		  
	int i;  
	
	char n1,n2,ln1,ln2,mask1,mask2;  
	   
	ln1 = 0b11111100;  
	ln2 = 0b11111000;  
	    
	mask1 = 0b11110000;  //0xF0
	mask2 = 0b00001111;  //0x0F
	    
	n1 = (position & mask1) | mask2;        
	n2 = ((position & mask2)<<4) | mask2;  
	   
	i2c_send_byte( n1 & ln1) ;  
	i2c_send_byte( n1 & ln2) ;  
	i2c_send_byte( n2 & ln1) ;  
	i2c_send_byte( n2 & ln2) ;  
	
	
}  
  
  
  
  
void send_simple_string_to_lcd(char *str) //A function to send Simple String to LCD 
{  
  
  
	int i;  
	for(i=0;(str[i]!=0x00);i++)  
		{  
		
		char chr = str[i];
		
		int i;  
	
		char n1,n2,ln1,ln2,mask1,mask2;  
			
		ln1 = 0b11111101;  
		ln2 = 0b11111001;  
			
		mask1 = 0b11110000;  
		mask2 = 0b00001111;  
		  
		n1 = (chr & mask1)| mask2;  
		n2 =  ((chr & mask2)<<4)|mask2;
			
		i2c_send_byte( n1 & ln1) ; 
		i2c_send_byte( n1 & ln2);      
		i2c_send_byte( n2 & ln1) ;  
		i2c_send_byte( n2 & ln2) ;  

		 
	
		}  
	  
  
}  

void lcd_init()
{

   /* -------------------------------------------------------------------- * 
    * Initialize the display, using the 4-bit mode initialization sequence * 
    * -------------------------------------------------------------------- */    
  
  
   sleep(0.4);                // wait 40msec  
   i2c_send_byte(0b00110100); // D7=0, D6=0, D5=1, D4=1, RS,RW=0 EN=1  
   i2c_send_byte(0b00110000); // D7=0, D6=0, D5=1, D4=1, RS,RW=0 EN=0  
  
   sleep(0.1);                // wait 10msec  
   i2c_send_byte(0b00110100); //   
   i2c_send_byte(0b00110000); // same  
   sleep(0.1);                // wait 10msec  
   i2c_send_byte(0b00110100); //  
   i2c_send_byte(0b00110000); // 8-bit mode init complete  
   sleep(0.1);                // wait 10msec  
   i2c_send_byte(0b00100100); //  
   i2c_send_byte(0b00100000); // switched now to 4-bit mode  
  
  
   /* -------------------------------------------------------------------- * 
    * 4-bit mode initialization complete. Now configuring the function set * 
    * -------------------------------------------------------------------- */  
   usleep(100);               // wait 100usec  
   i2c_send_byte(0b00100100); //  
   i2c_send_byte(0b00100000); // keep 4-bit mode  
   i2c_send_byte(0b10000100); //  D3=2lines
   i2c_send_byte(0b10000000); // D2=char5x8  
  
  
  
   clear_display();
  
  
	display_on();
  
    sleep(1); //delay of 1 second	
}
  
  
  
void main() {   
	
	i2c_start();//Start I2C Communication
	
	lcd_init();//Initialize the LCD
  
	clear_display();  //Clear the display

	 
	send_simple_string_to_lcd("CAR OVERSPEED");//Print a message on LCD
	go_to(2,3);//Go to Line 2
	send_simple_string_to_lcd("DETECTION SYSTEM");//Print a message on LCD
		 
	  
	close(i2cFile);  //Stop i2c communication  
} 
