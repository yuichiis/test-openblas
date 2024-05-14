#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dsum not found\n";
typedef double (CALLBACK* PFNcblas_dsum)( /* cblas_dsum */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST double *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_dsum _g_cblas_dsum = NULL;
double cblas_dsum(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST double *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_dsum==NULL) {
        _g_cblas_dsum = rindow_load_libopenblas_func("cblas_dsum"); 
        if(_g_cblas_dsum==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_dsum(
        n,
        x,
        incx    
    );
}
