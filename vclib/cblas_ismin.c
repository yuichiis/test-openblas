#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_ismin not found\n";
typedef CBLAS_INDEX (CALLBACK* PFNcblas_ismin)( /* cblas_ismin */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST float *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_ismin _g_cblas_ismin = NULL;
CBLAS_INDEX cblas_ismin(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST float *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_ismin==NULL) {
        _g_cblas_ismin = rindow_load_libopenblas_func("cblas_ismin"); 
        if(_g_cblas_ismin==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_ismin(
        n,
        x,
        incx    
    );
}
