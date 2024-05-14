#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_damin not found\n";
typedef double (CALLBACK* PFNcblas_damin)( /* cblas_damin */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST double *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_damin _g_cblas_damin = NULL;
double cblas_damin(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST double *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_damin==NULL) {
        _g_cblas_damin = rindow_load_libopenblas_func("cblas_damin"); 
        if(_g_cblas_damin==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_damin(
        n,
        x,
        incx    
    );
}
