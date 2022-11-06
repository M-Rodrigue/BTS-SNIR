/***********************************************

 * Lecture du lecteur code BARRE RS232

 * 8bits 9600 b/s

 * 2022 Bogt

 * ********************************************/


/*

 * 

stty -F /dev/ttyUSB0 -a

speed 9600 baud; rows 0; columns 0; line = 0;

intr = ^C; quit = ^\; erase = ^?; kill = ^U; eof = ^D; eol = <undef>; eol2 = <undef>; swtch = <undef>; start = ^Q; stop = ^S; susp = ^Z; rprnt = ^R; werase = ^W; lnext = ^V; discard = ^O; min = 1; time = 0;

-parenb -parodd -cmspar cs8 hupcl -cstopb cread clocal -crtscts

-ignbrk -brkint -ignpar -parmrk -inpck -istrip -inlcr -igncr icrnl ixon -ixoff -iuclc -ixany -imaxbel -iutf8

opost -olcuc -ocrnl onlcr -onocr -onlret -ofill -ofdel nl0 cr0 tab0 bs0 vt0 ff0

isig icanon iexten echo echoe echok -echonl -noflsh -xcase -tostop -echoprt echoctl echoke -flusho -extproc

 *      stty -F /dev/ttyUSB0 -g # sauve 

 * 	stty -F /dev/ttyUSB0 500:5:cbd:8a3b:3:1c:7f:15:4:0:1:0:11:13:1a:0:12:f:17:16:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0:0

*/


#include <stdlib.h>

#include <stdio.h>

#include <string.h>


/* Linux headers */

#include <fcntl.h>     /* Contains file controls like O_RDWR */

#include <errno.h>     /* Error integer and strerror() function */

#include <termios.h>   /* Contains POSIX terminal control definitions */

#include <unistd.h>    /* write(), read(), close() */


#define device "/dev/ttyS4"


int main(int argc, char ** argv) 

{


int num_bytes;

unsigned char read_buf[256];

int serial_port;


serial_port = open(device, O_RDWR);


if (serial_port < 0) 

	{

		printf ("Pas possible d'ouvrir ce DEVICE %s \n",device);

		return EXIT_FAILURE;

	}



num_bytes = 0;

printf ("Scanner le code bar :\n");

do

{

  num_bytes = read(serial_port, &read_buf, 256 );

  /* n is the number of bytes read. n may be 0 if no bytes were received, and can also be -1 to signal an error.*/

  if (num_bytes < 0) {

      printf("Error reading: %s", strerror(errno));

      return EXIT_FAILURE;

  }

}

while (read_buf == 0 );

  /* Here we assume we received ASCII data, but you might be sending raw bytes (in that case, don't try and

     print it to the screen like this!) */


 printf("Read %i bytes. Received message: %s\n", num_bytes, read_buf);

 close(serial_port);

 return EXIT_SUCCESS;

}
