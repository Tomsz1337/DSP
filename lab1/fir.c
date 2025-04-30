#include "fir.h"
#include "Qcode.h"
#define NOF_SAMPLES 16

const float firQ_coeff[NOF_SAMPLES] = {112,   243,   618,    1293,   2217,   3225,   4089,   4587,   4587,   4089,   3225,   2217,   1293,   618,    243,   112  };

float circural_buff[NOF_SAMPLES];

static void bufferStep(float new_sample){
    uint8_t sampleCtr;
    for(sampleCtr = NOF_SAMPLES; sampleCtr > 0; sampleCtr--)
        circural_buff[sampleCtr] = circural_buff[sampleCtr-1];

    circural_buff[0] = new_sample;
}


/*
    FIR_Init:
    Clears circural buffer
*/
void FIR_Init(void){
    uint8_t sampleCtr;
    for(sampleCtr = 0; sampleCtr < NOF_SAMPLES; sampleCtr++){
        circural_buff[sampleCtr] = 0;
    }
}


/*
    FIRQ_filter:
    Calculates one FIR output and gets one input
*/
int32_t FIRQ_filter(int32_t data){
    float Accumulator = 0;
    uint8_t sampleCtr;

    bufferStep(data);

    for(sampleCtr = 0; sampleCtr < NOF_SAMPLES; sampleCtr++)
    {
    	Accumulator += circural_buff[sampleCtr] * firQ_coeff[sampleCtr];
    }
        

    return Accumulator;
}


