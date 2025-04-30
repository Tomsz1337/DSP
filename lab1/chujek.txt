/* ###################################################################
**     Filename    : main.c
**     Project     : dsc1
**     Processor   : MC56F8006_48_LQFP
**     Version     : Driver 01.16
**     Compiler    : CodeWarrior DSP C Compiler
** ###################################################################*/

#include "Cpu.h"
#include "Events.h"
#include "TI1.h"
#include "CS.h"
#include "AD1.h"
#include "SM1.h"
#include "LED1.h"
#include "SW1.h"
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#define B0 2029    // Q1.15
#define B1 4058
#define B2 2029

#define A1 -20732  // Q2.14
#define A2 10080

#define Q15 15
#define Q14 14

static int16_t x1 = 0, x2 = 0;
static int32_t y1 = 0, y2 = 0;

int16_t iir_filter(int16_t x0)
{
    int32_t acc;

    // FIR part (numerator)
    acc  = (int32_t)B0 * x0;
    acc += (int32_t)B1 * x1;
    acc += (int32_t)B2 * x2;

    // IIR part (feedback - denominator)
    acc -= ((int32_t)A1 * y1) >> Q14;
    acc -= ((int32_t)A2 * y2) >> Q14;

    // Shift result from Q30 to Q15
    acc = acc >> Q15;

    // Saturation
    if (acc > 32767) acc = 32767;
    if (acc < -32768) acc = -32768;

    // Update history
    x2 = x1;
    x1 = x0;
    y2 = y1;
    y1 = acc;

    return (int16_t)acc;
}

// Sending single sample to DAC
void Send_DAC(int16_t sample)
{
    word out;
    out = (sample >> 4) + (word)2048;
    out &= 0x0FFF;
    out |= 0x3000;
    SM1_SendChar(out);
}

void main(void)
{
    static int16_t Y;

    PE_low_level_init();
  

    for(;;) {
        if(data_ready)
        {
            data_ready = FALSE;
            if(SW1_GetVal())
            {
            	Y = X;
            } else 
            {	

            // Apply IIR filter to input sample
            Y = iir_filter(X);
            }

            // Send output sample to DAC
            Send_DAC(Y);
        }
    }
}

/* END main */
/*
** ###################################################################
**     This file was created by Processor Expert 10.3
**     for the Freescale 56800 series of microcontrollers.
** ###################################################################*/
