/*
 * iir.c
 *
 *  Created on: Mar 21, 2025
 *      Author: student
 */

#include "iir.h"
#include <stdint.h>
#include <stdio.h>
#define NOF_SAMPLES_IIR 3

const int32_t 	iirQ_coeff_num[3]  = {2029, 4058, 2029};	//Q1.15
const int32_t 	iirQ_coeff_den[3] = {16384, -20732, 10080}; //Q2.14

int32_t cbuff[3];
int32_t cbuff2[3];

static void bufferStep(int32_t new_sample)
{
    uint8_t sampleCtr;
    for(sampleCtr = NOF_SAMPLES_IIR; sampleCtr > 0; sampleCtr--)
        cbuff[sampleCtr] = cbuff[sampleCtr-1];

    cbuff[0] = new_sample;
}

static void bufferStep2(int32_t new_sample)
{
    uint8_t sampleCtr;
    for(sampleCtr = NOF_SAMPLES_IIR; sampleCtr > 0; sampleCtr--)
        cbuff2[sampleCtr] = cbuff2[sampleCtr-1];

    cbuff2[0] = new_sample;
}

void IIR_Init(void){
    uint8_t sampleCtr;
    for(sampleCtr = 0; sampleCtr < NOF_SAMPLES_IIR; sampleCtr++){
        cbuff[sampleCtr] = 0;
        cbuff2[sampleCtr] = 0;
    }
}
int32_t IIR_filter_TOP(int32_t data)
{
    int32_t acc = 0;
    int32_t reg = 0;
    uint8_t sampleCtr;
    
    bufferStep(data);

    for(sampleCtr = 0; sampleCtr < NOF_SAMPLES_IIR; sampleCtr++)
    {
        acc += (int32_t)cbuff[sampleCtr] * iirQ_coeff_num[sampleCtr];
    }
    printf("wynik dla licznika: %ld\n", acc);
    for(sampleCtr = 0; sampleCtr < NOF_SAMPLES_IIR; sampleCtr++)  
    {
    	reg += cbuff[sampleCtr] * iirQ_coeff_den[sampleCtr]; 
    }
    printf("wynik dla mianownika: %ld\n", reg);
    	
    
    return acc + reg;
}
int32_t IIR_filter_BOT(int32_t data)
{
	int32_t acc = 0;
	uint8_t sampleCtr; 
	
	bufferStep2(data);
	
	for(sampleCtr = 0; sampleCtr < NOF_SAMPLES_IIR; sampleCtr++)  
	{
		acc += cbuff2[sampleCtr] * iirQ_coeff_den[sampleCtr]; 
	}
	printf("wynik dla mianownika: %ld\n", acc);
	return acc;
}

int32_t IIR(int16_t data)
{
	int32_t result1;
	int32_t result2;
	result1 = IIR_filter_TOP(data);
	result2 = IIR_filter_BOT(result1);
	return result1 + result2;
}
