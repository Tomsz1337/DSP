/*
 * fir.h
 *
 *  Created on: Mar 21, 2025
 *      Author: student
 */

#ifndef FIR_H_
#define FIR_H_
#include <stdint.h>

float FIR_filter(float data);
void FIR_Init(void);
int32_t FIRQ_filter(int32_t data);
#endif /* FIR_H_ */
