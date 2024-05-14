#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_samin not found\n";
typedef float (CALLBACK* PFNcblas_samin)( /* cblas_samin */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST float *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_samin _g_cblas_samin = NULL;
float cblas_samin(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST float *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_samin==NULL) {
        _g_cblas_samin = rindow_load_libopenblas_func("cblas_samin"); 
        if(_g_cblas_samin==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_samin(
        n,
        x,
        incx    
    );
}
