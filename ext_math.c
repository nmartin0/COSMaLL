#include <time.h>
#include <math.h>
#include <stdlib.h>

#include "ext_math.h"

#define EULER_NUMBER 2.718281828459045235360287471352

double sigmoid(double x) {
    return 1 / (1 + pow(EULER_NUMBER, (-x)) );
}

double gen_rand() {
    srand(time(NULL) + clock());
    int rand_num = rand();
    int dist = abs(rand_num);
    double scale = (double) RAND_MAX / dist;
    double pcent = 100 / scale;
    return pcent / 100;
}

int activ(double x, double thres) {
    if (x > thres) return 1;
    else return 0;
}

int main(){}
