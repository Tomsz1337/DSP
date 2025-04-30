#include <stdio.h>
#include <stdint.h>
#include "fir.h"

#define NUM_SAMPLES 16
int32_t input_signal[NUM_SAMPLES];
int32_t output_signal[NUM_SAMPLES];

int main(void) {
    
    for (int i = 0; i < NUM_SAMPLES; i++) {
        input_signal[i] = (i < 1) ? 1 : 0;
    }

    FIR_Init();

    for (int i = 0; i < NUM_SAMPLES; i++) {
        output_signal[i] = FIRQ_filter(input_signal[i]);
    }

    printf("Idx\tInput\tOutput\n");
    for (int i = 0; i < NUM_SAMPLES; i++) {
        printf("%2d\t%6ld\t%6ld\n", i, (long)input_signal[i], (long)output_signal[i]);
    }

    return 0;
}
