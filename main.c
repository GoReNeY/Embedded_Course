#include "math.h"
#include "stdio.h"


void calculate_functions(double* z1, double* z2, int x, int y){
    *z1 = ((powf(cos(x), 4) + powf(sin(y), 2)) + (0.25 * powf(sin(2*x), 2))) - 1;
    *z2 = sin(x+y) * sin(x-y);
}

int main(){
    double z1, z2;
    calculate_functions(&z1, &z2, 5, 10);

    printf("z1 = %f \nz2 = %f", z1, z2);

    return 0;
}
