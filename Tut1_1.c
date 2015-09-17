/* ADC - POTENTIOMETER - LIGHT */


#include <hidef.h>         /* common defines and macros */
#include "SCI.h"
#include "printf.h"
#include "device_headers.h" /*Chip specific defines and macros*/

void main(void) {

/* Makes PTB[4:5] output pins to allow the user to turn on/off LED[2] in application. */
  DDRB_BIT4 = 1;
  DDRB_BIT5 = 1;
  DDRB_BIT6 = 1;
  DDRB_BIT7 = 1;

  PORTB_BIT4 = OFF;   //turn off user1 LED
  PORTB_BIT5 = OFF;   //turn off user2 LED
  PORTB_BIT6 = OFF;   //turn off user3 LED
  PORTB_BIT7 = OFF;   //turn off user4 LED


  /* Initializes ATD Channel 1 to continously sample PBMCUSLK Potentiometer to allow the
     user to read POT, which holds the instantaneous ATD Ch.1 data result. */


  ATDCTL2 = 0xC0;     //ATD power up enabled
              				//ATD fast flag clear enabled
                      //ATD interrupts disabled
  ATDCTL3 = 0x08;			//ATD conversions per sequence = 1
                      //ATD in non-fifo mode, freeze disabled
  ATDCTL4 = 0x85;     //ATD set to 8-bit resolution
                      //ATD sample time =  2 ATD conv.clock periods
  ATDCTL5 = 0xB5;     //ATD result is left-justified and unsigned

  for(;;) {

    //POTENTIOMETER--------------------------------------------
    if(ATDDR0L<49){
      PORTB_BIT4 = ON;
      PORTB_BIT5 = ON;
      PORTB_BIT6 = ON;
      PORTB_BIT7 = ON;
    }

    if(ATDDR0L>50){
      PORTB_BIT4 = OFF;           //turn on user1 LED
    }

    if(ATDDR0L>100){
      PORTB_BIT5 = OFF;           //turn on user2 LED
    }

    if(ATDDR0L>150){
      PORTB_BIT6 = OFF;           //turn on user3 LED
    }

    if(ATDDR0L>200){
      PORTB_BIT7 = OFF;           //turn on user4 LED
    }


  } /* wait forever */
}
