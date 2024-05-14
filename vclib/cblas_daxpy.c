#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_daxpy not found\n";
typedef void (CALLBACK* PFNcblas_daxpy)( /* cblas_daxpy */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST double            /* alpha */,
    OPENBLAS_CONST double *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    double *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_daxpy _g_cblas_daxpy = NULL;
void cblas_daxpy(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST double            alpha,
    OPENBLAS_CONST double *            x,
    OPENBLAS_CONST blasint            incx,
    double *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_daxpy==NULL) {
        _g_cblas_daxpy = rindow_load_libopenblas_func("cblas_daxpy"); 
        if(_g_cblas_daxpy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_daxpy(
        n,
        alpha,
        x,
        incx,
        y,
        incy    
    );
}
