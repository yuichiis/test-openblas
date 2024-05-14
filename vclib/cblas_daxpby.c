#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_daxpby not found\n";
typedef void (CALLBACK* PFNcblas_daxpby)( /* cblas_daxpby */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST double            /* alpha */,
    OPENBLAS_CONST double *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    OPENBLAS_CONST double            /* beta */,
    double *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_daxpby _g_cblas_daxpby = NULL;
void cblas_daxpby(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST double            alpha,
    OPENBLAS_CONST double *            x,
    OPENBLAS_CONST blasint            incx,
    OPENBLAS_CONST double            beta,
    double *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_daxpby==NULL) {
        _g_cblas_daxpby = rindow_load_libopenblas_func("cblas_daxpby"); 
        if(_g_cblas_daxpby==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_daxpby(
        n,
        alpha,
        x,
        incx,
        beta,
        y,
        incy    
    );
}
