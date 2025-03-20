#ifndef Q_CODE_H
#define Q_CODE_H

#include <stdint.h>
#include <stdio.h>

void print_q230(uint32_t number);
void print_q115(uint16_t number);
uint32_t Q115add(uint16_t a, uint16_t b);
uint32_t Q115sub(uint16_t a, uint16_t b);
uint32_t Q115mul(uint16_t a, uint16_t b);
uint32_t Q115div(uint16_t a, uint16_t b);
void printOperation(int16_t a, int16_t b, int32_t y, char operation);
double calculateQ115(uint16_t val);
void Q115operationsTest(uint16_t a, uint16_t b);
#endif
