#include <stdio.h>
#include <stdint.h>
#include "iir.h"

#define NUM_SAMPLES 16
int16_t input_signal[NUM_SAMPLES];
int16_t output_signal[NUM_SAMPLES];

int main(void) {
    
    for (int i = 0; i < NUM_SAMPLES; i++) {
        input_signal[i] = (i < 1) ? 1 : 0;  
    }

    IIR_Init();

    for (int i = 0; i < NUM_SAMPLES; i++) {
        output_signal[i] = IIR_filter(input_signal[i]);
    }

    printf("Idx\tInput\tOutput\n");
    for (int i = 0; i < NUM_SAMPLES; i++) {
        printf("%2d\t%6d\t%6d\n", i, input_signal[i], output_signal[i]);
    }

    return 0;
}
