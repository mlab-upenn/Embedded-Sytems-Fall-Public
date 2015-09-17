/* ADC  - LIGHT SENSOR - MICROPHONE*/

#include <hidef.h>         /* common defines and macros */
#include "SCI.h"
#include "printf.h"
#include "device_headers.h" /*Chip specific defines and macros*/

void main(void) {
int delay;


  ATDCTL2 = 0xC0;     //ATD power up enabled
              				//ATD fast flag clear enabled
                      //ATD interrupts disabled
  ATDCTL3 = 0x08;			//ATD conversions per sequence = 1
                      //ATD in non-fifo mode, freeze disabled
  ATDCTL4 = 0x85;     //ATD set to 8-bit resolution
                      //ATD sample time =  2 ATD conv.clock periods
  ATDCTL5 = 0xB5;     //ATD result is left-justified and unsigned

  SCIInit();

  EnableInterrupts;

  for(;;) {

    for(delay=0; delay<10000; delay++);

    printf("atd: ");
    printf("%d ", ATDDR0L);
    printf("\r\n");


  } /* wait forever */
}




