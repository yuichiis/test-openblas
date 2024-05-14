#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dsdot not found\n";
typedef double (CALLBACK* PFNcblas_dsdot)( /* cblas_dsdot */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST float *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    OPENBLAS_CONST float *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_dsdot _g_cblas_dsdot = NULL;
double cblas_dsdot(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST float *            x,
    OPENBLAS_CONST blasint            incx,
    OPENBLAS_CONST float *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_dsdot==NULL) {
        _g_cblas_dsdot = rindow_load_libopenblas_func("cblas_dsdot"); 
        if(_g_cblas_dsdot==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_dsdot(
        n,
        x,
        incx,
        y,
        incy    
    );
}
