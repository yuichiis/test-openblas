#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_caxpy not found\n";
typedef void (CALLBACK* PFNcblas_caxpy)( /* cblas_caxpy */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* alpha */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    void *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_caxpy _g_cblas_caxpy = NULL;
void cblas_caxpy(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            alpha,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx,
    void *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_caxpy==NULL) {
        _g_cblas_caxpy = rindow_load_libopenblas_func("cblas_caxpy"); 
        if(_g_cblas_caxpy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_caxpy(
        n,
        alpha,
        x,
        incx,
        y,
        incy    
    );
}
