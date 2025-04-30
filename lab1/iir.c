#include "iir.h"

// Współczynniki filtra:
// licznik: Q1.15
static const int16_t b[3] = {2029, 4058, 2029};

// mianownik: Q2.14 
static const int16_t a[3] = {16384,-20732, 10080};

// Bufory wejściowe i wyjściowe
static int16_t x[3] = {0};
static int16_t y[3] = {0};

void IIR_Init(void) {
    for (int i = 0; i < 3; i++) {
        x[i] = 0;
        y[i] = 0;
    }
}

int16_t IIR_filter(int16_t input) {
    // Przesuwanie próbek
    x[2] = x[1];
    x[1] = x[0];
    x[0] = input;

    y[2] = y[1];
    y[1] = y[0];

    // Liczenie licznika: Q1.15 * Q1.15 = Q30
    int32_t acc = 0;
    acc += (int32_t)b[0] * x[0];
    acc += (int32_t)b[1] * x[1];
    acc += (int32_t)b[2] * x[2];

    // Liczenie mianownika: Q2.14 * Q1.15 = Q29 → przesunięcie >>1 by dopasować do Q2.30
    acc -= ((int32_t)a[0] * y[1]) >> 1;
    acc -= ((int32_t)a[1] * y[2]) >> 1;

    // Przeskalowanie z Q30 → Q15 z zaokrągleniem
    acc = (acc + (1 << 14)) >> 15;

    if (acc > 32767) acc = 32767;
    else if (acc < -32768) acc = -32768;

    // Zapisanie do bufora wyjściowego
    y[0] = (int16_t)acc;

    return y[0];
}

