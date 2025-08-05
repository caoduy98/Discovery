#include <33FJ128MC710.h>
#device adc = 12

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOWRTB                   //Boot block not write protected               
#FUSES NORSS                    //No secure segment RAM
#FUSES NOWRTSS                  //Secure segment not write protected
#FUSES NOPROTECT                //Code not protected from reading
#FUSES PR                       //Primary Oscillator
#FUSES IESO                     //Internal External Switch Over mode enabled
#FUSES HS                       //High speed Osc (> 4mhz for PCM/PCH) (>10mhz for PCD)
#FUSES CKSFSM                   //Clock Switching is enabled, fail Safe clock monitor is enabled
#FUSES NOPWMPIN                 //PWM outputs drive active state upon Reset
#FUSES NOJTAG                   //JTAG disabled
#FUSES NODEBUG                  //No Debug mode for ICD

#use delay(crystal=20000000)

