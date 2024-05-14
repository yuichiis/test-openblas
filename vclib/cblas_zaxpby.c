#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_zaxpby not found\n";
typedef void (CALLBACK* PFNcblas_zaxpby)( /* cblas_zaxpby */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* alpha */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    OPENBLAS_CONST void *            /* beta */,
    void *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_zaxpby _g_cblas_zaxpby = NULL;
void cblas_zaxpby(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            alpha,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx,
    OPENBLAS_CONST void *            beta,
    void *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_zaxpby==NULL) {
        _g_cblas_zaxpby = rindow_load_libopenblas_func("cblas_zaxpby"); 
        if(_g_cblas_zaxpby==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_zaxpby(
        n,
        alpha,
        x,
        incx,
        beta,
        y,
        incy    
    );
}
