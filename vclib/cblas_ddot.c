#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_ddot not found\n";
typedef double (CALLBACK* PFNcblas_ddot)( /* cblas_ddot */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST double *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    OPENBLAS_CONST double *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_ddot _g_cblas_ddot = NULL;
double cblas_ddot(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST double *            x,
    OPENBLAS_CONST blasint            incx,
    OPENBLAS_CONST double *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_ddot==NULL) {
        _g_cblas_ddot = rindow_load_libopenblas_func("cblas_ddot"); 
        if(_g_cblas_ddot==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_ddot(
        n,
        x,
        incx,
        y,
        incy    
    );
}
