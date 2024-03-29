
#include <stdio.h>
#include <cblas.h>

extern int rindow_load_openblas_dll();
extern void rindow_unload_openblas_dll();

int main() {
    if(rindow_load_openblas_dll()) {
        return -1;
    }
    blasint n = 4;
    blasint incx = 1;
    float result;
    //                 0     1     2     3 
    float x[4] = {  1.0,  2.0,  3.0,  4.0 };

    result = cblas_sasum(n, x, incx);

    printf("sasum=%f\n",result);

    rindow_unload_openblas_dll();
    return 0;
}
