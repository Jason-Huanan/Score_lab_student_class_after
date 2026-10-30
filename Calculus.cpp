#include"Calculus.h"
double calcSum(const int* row, int count) {
    double sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += *(row + i);
    }
    return sum;
}

double calcAverage(const int* row, int count) {
    return calcSum(row, count) / count;
}

double calcMax(const int* row, int count) {
    double maxValue = row[0];
    for (int j = 1; j < count; ++j) {
        if (row[j] > maxValue) {
            maxValue = row[j];
        }
    }
    return maxValue;
}