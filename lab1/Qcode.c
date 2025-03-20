/*
 * Qcode.c
 *
 *  Created on: Mar 19, 2025
 *      Author: tomasz
 */
#include "Qcode.h"

//Adds two numbers in Q1.15 and returns result in Q2.30
uint32_t Q115add(uint16_t a, uint16_t b)
{
	
	return ((uint32_t)a + (uint32_t)b)<<15;
}

//Subtracts two numbers in Q1.15 and returns result in Q2.30
uint32_t Q115sub(uint16_t a, uint16_t b)
{
	return ((uint32_t)a - (uint32_t)b)<<15;
}

//Multiplies two numbers in Q1.15 and returns result in Q2.30
uint32_t Q115mul(uint16_t a, uint16_t b)
{
	return ((uint32_t)a * (uint32_t)b);
}

//Divides two numbers in Q1.15 and returns result in Q2.30
uint32_t Q115div(uint16_t a, uint16_t b)
{
	return (((uint32_t)a<<16) / (uint32_t)b);
}

double calculateQ115(uint16_t val){
    double div=1;
    double sum=0;

    int i;
    for(i=0; i < 16; i++){
        sum += (val & (1<<15))? div : 0;
        val = val << 1;
        div = div/2;
    }

    return sum;
}


double calculateQ230(uint32_t val){
    double div=1;
    double sum=0;

    int i;
    for(i=0; i < 32; i++){
        sum += (val & (1<<32))? div : 0;
        val = val << 1;
        div = div/2;
    }

    return sum;
}


void Q115operationsTest(uint16_t a, uint16_t b)
{
	printf("a = %X\n", a);
	printf("a = %f\n", calculateQ115(a));
	printf("b = %X\n", b);
	printf("b = %f \n", calculateQ115(b));
	printf("Q115add = %lx\n", Q115add(a,b));
	
	printf("Q115sub = %lx\n", Q115sub(a,b));
	
	printf("Q115mul = %lX\n", Q115mul(a,b));
	
	printf("Q115div = %lX\n", Q115div(a,b));
	
}


