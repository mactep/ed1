#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void calc_esfera(float r, float* area, float* volume) {
    *area = 4 * 3.14 * r * r;
    *volume = 4 * 3.14 * r * r * r / 3;
}

/*
int main() {
    float *area_superficie = (float*) malloc(sizeof(float));
    float *volume = (float*) malloc(sizeof(float));
    float r = 10;

    calc_esfera(r, area_superficie, volume);
    printf("area da superfície: %f\n", *area_superficie);
    printf("volume: %f\n", *volume);

    return 0;
}
*/

int raizes(float a, float b, float c, float* x1, float* x2) {
    float delta = (b * b) - (4 * a * c);

    if (delta == 0 || delta > 0) {
        *x1 = ((-1 * b) + sqrt(delta)) / (2 * a);
        *x2 = ((-1 * b) - sqrt(delta)) / (2 * a);

        return 0;
    } else {
        return 1;
    }
}

/*
int main() {
    float *x1 = (float*) malloc(sizeof(float));
    float *x2 = (float*) malloc(sizeof(float));
    float a = 1;
    float b = 3;
    float c = -4;

    if (!raizes(a, b, c, x1, x2)) {
        printf("x1: %f\n", *x1);
        printf("x2: %f\n", *x2);
    } else {
        printf("não existem raízes reais\n");
    }

    return 0;
}
*/

int pares(int n, int* vet) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!(*(vet + i) % 2)) {
            count++;
        }
    }

    return count;
}

/*
int main() {
    int tamain = 10;
    int aux[10] = {0,1,2,3,4,5,6,7,8,9};
    int* malakoi = (int*) malloc(sizeof(int) * tamain);

    malakoi = aux;

    printf("%d\n", pares(tamain, malakoi));

    return 0;
}
*/

void inverte (int n, int* vet) {
    int aux;

    for (int i = 0; i < (n / 2); i++) {
        aux = *(vet + i);
        *(vet + i) = *(vet + (n - i - 1));
        *(vet + (n - i - 1)) = aux;
    }
}

/*
int main() {
    int tamain = 10;
    int aux[10] = {0,1,2,3,4,5,6,7,8,9};
    int* malakoi = (int*) malloc(sizeof(int) * tamain);

    malakoi = aux;
    inverte(tamain, malakoi);

    for (int i = 0; i < tamain; i++) {
        printf("%d ", *(malakoi + i));
    }
    printf("\n");

    return 0;
}
*/

double avalia(double* poli, int grau, double x) {
    double sum = 0;
    for (int i = 0; i <= grau; i++) {
        sum += *(poli + i) * pow(x, i);
    }

    return sum;
}

int main() {
    int grau = 2;
    double aux[3] = {5, 6, 3};
    double* malakoi = (double*) malloc(sizeof(double) * grau);
    double x = 7;

    malakoi = aux;
    printf("%f", avalia(malakoi, grau, x));

    return 0;
}
