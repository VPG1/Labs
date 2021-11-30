#include "for_vector.h"
#include <cmath>


// функци заполнения вектора числами ввида 0.1 * tan(0.1(i + 1)) где i oт 1 до длинны массива
void fillVector(double* vector, const int size){
    for(int i = 0; i < size; ++i){
        vector[i] = 0.1 * tan(0.1 * (i + 1));
    }
}

// функция произведения вектроров
double multiply(double* vector1, double* vector2, const int size){
    double result = 0;
    for(int i = 0; i < size; ++i){
        result += vector1[i] * vector2[i];
    }
    return result;
}
