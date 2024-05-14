#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_saxpy not found\n";
typedef void (CALLBACK* PFNcblas_saxpy)( /* cblas_saxpy */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST float            /* alpha */,
    OPENBLAS_CONST float *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    float *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_saxpy _g_cblas_saxpy = NULL;
void cblas_saxpy(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST float            alpha,
    OPENBLAS_CONST float *            x,
    OPENBLAS_CONST blasint            incx,
    float *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_saxpy==NULL) {
        _g_cblas_saxpy = rindow_load_libopenblas_func("cblas_saxpy"); 
        if(_g_cblas_saxpy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_saxpy(
        n,
        alpha,
        x,
        incx,
        y,
        incy    
    );
}
