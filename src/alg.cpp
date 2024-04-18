// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"
#include <cmath>

double pown(double value, uint16_t n) {
    return std::pow(value, n);
}

uint64_t fact(uint16_t n) {
    if (n == 0) {
        return 1;
    }
    return n * fact(n - 1);
}

double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
    double result = 0;
    for (uint16_t n = 0; n < count; ++n) {
        result += calcItem(x, n);
    }
    return result;
}

double sinn(double x, uint16_t count) {
    double result = 0;
    for (uint16_t n = 0; n < count; ++n) {
        result += (n % 2 == 0 ? 1 : -1) * calcItem(x, 2 * n + 1);
    }
    return result;
}

double cosn(double x, uint16_t count) {
    double result = 0;
    for (uint16_t n = 0; n < count; ++n) {
        result += (n % 2 == 0 ? 1 : -1) * calcItem(x, 2 * n);
    }
    return result;
}
