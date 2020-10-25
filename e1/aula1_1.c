#include <stdio.h>

void sum(int* pointer1, int* pointer2, int* pointer3) {
    *pointer1 = *pointer2 + *pointer3;
}
void subtract(int* pointer1, int* pointer2, int* pointer3) {
    *pointer1 = *pointer2 - *pointer3;
}
void multiply(int* pointer1, int* pointer2, int* pointer3) {
    *pointer1 = *pointer2 * *pointer3;
}
void divide(int* pointer1, int* pointer2, int* pointer3) {
    *pointer1 = *pointer2 / *pointer3;
}

int main() {
    int a = 1;
    int b = 2;
    int c = 3;
    int d = 4;
    int *pa;
    int *pb;
    int *pc;
    int *pd;

    pa = &a;
    pb = &b;
    pc = &c;
    pd = &d;

    sum(pc, pa, pd);
    printf("%d\n", *pc);

    subtract(pc, pc, pb);
    printf("%d\n", *pc);

    multiply(pc, pb, pd);
    printf("%d\n", *pc);

    divide(pc, pc, pa);
    printf("%d\n", *pc);

    return 0;
}
