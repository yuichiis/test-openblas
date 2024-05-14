#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_zaxpy not found\n";
typedef void (CALLBACK* PFNcblas_zaxpy)( /* cblas_zaxpy */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* alpha */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    void *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_zaxpy _g_cblas_zaxpy = NULL;
void cblas_zaxpy(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            alpha,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx,
    void *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_zaxpy==NULL) {
        _g_cblas_zaxpy = rindow_load_libopenblas_func("cblas_zaxpy"); 
        if(_g_cblas_zaxpy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_zaxpy(
        n,
        alpha,
        x,
        incx,
        y,
        incy    
    );
}
