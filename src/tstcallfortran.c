#include <stdio.h>

extern void fsim_( int *i, double *r );


int main() {

    int i = 100;
    double r = 23.0;

    fsim_( &i, &r );

    printf( "%d, %lf \n", i, r );

    return 0;
}
