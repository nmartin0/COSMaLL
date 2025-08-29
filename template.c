#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float genRandom() {
    srand(time(NULL) + clock());
    int rand_num = rand();
    int distance = abs(rand_num);
    float scalar = (float) RAND_MAX / distance;
    float percent = 100 / scalar;
    return percent / 100;
}

#define INPUTS 4
typedef struct {
    float input[INPUTS];
    float weight[INPUTS];
    float sum;
} perceptron;

void init_perceptron(perceptron *p) {
    for (int i = 0; i < INPUTS; i++) {
        p->input[i] = genRandom();
        p->weight[i] = genRandom(); //DELETE
    }
}

void show_perceptron(perceptron *p) {
    for (int i = 0; i < INPUTS; i++) {
        printf("Perceptron input %d: %f\n", i, p->input[i]);
    }
}

#define EULER 2.71828
float sigmoid(float x) {
    return 1 / (1 + pow(EULER, (-x)));
}

float weightedSum(perceptron *p) {
    float wsum;
    for (int i = 0; i < INPUTS; i++) {
        wsum += p->input[i] * p->weight[i];
        printf("p->input[%d]: %f\n", i, p->input[i]);
        printf("p->weight[%d]: %f\n", i, p->weight[i]);
        printf("weighed sum iteration #%d: %f\n", i, wsum);
    }

    return wsum;
}

int activation(float val) {
    if (val > 0.5) return 1;
    else return 0;
} 

typedef struct {
    float lr;
    int epochs;
    int input_sz;
    float bias;
    int misses;
} env;

void init_env(env *e) {
    e->bias = genRandom();
}

int main() {
    perceptron p;
    env e;
    init_env(&e);
    init_perceptron(&p);
    show_perceptron(&p);
    printf("bias: %f\n", e.bias);
    printf("sigmoid: %f\n", sigmoid(e.bias));
    p.sum = weightedSum(&p);
    printf("weightedSum = %f\n", p.sum);
    printf("Activation: %d\n", activation(e.bias)); // just testing bias
}
