#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dasum not found\n";
typedef double (CALLBACK* PFNcblas_dasum)( /* cblas_dasum */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST double *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_dasum _g_cblas_dasum = NULL;
double cblas_dasum(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST double *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_dasum==NULL) {
        _g_cblas_dasum = rindow_load_libopenblas_func("cblas_dasum"); 
        if(_g_cblas_dasum==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_dasum(
        n,
        x,
        incx    
    );
}
