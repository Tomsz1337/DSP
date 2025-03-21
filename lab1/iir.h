/*
 * iir.h
 *
 *  Created on: Mar 21, 2025
 *      Author: student
 */

#ifndef IIR_H_
#define IIR_H_
#include <stdint.h>

void IIR_Init(void);
int32_t IIR_filter_BOT(int32_t data);
int32_t IIR_filter_TOP(int32_t data);
int32_t IIR(int16_t data);
#endif /* IIR_H_ */
