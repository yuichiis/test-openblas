#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_damax not found\n";
typedef double (CALLBACK* PFNcblas_damax)( /* cblas_damax */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST double *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_damax _g_cblas_damax = NULL;
double cblas_damax(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST double *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_damax==NULL) {
        _g_cblas_damax = rindow_load_libopenblas_func("cblas_damax"); 
        if(_g_cblas_damax==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_damax(
        n,
        x,
        incx    
    );
}
