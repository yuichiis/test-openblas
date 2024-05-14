#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_scamin not found\n";
typedef float (CALLBACK* PFNcblas_scamin)( /* cblas_scamin */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_scamin _g_cblas_scamin = NULL;
float cblas_scamin(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_scamin==NULL) {
        _g_cblas_scamin = rindow_load_libopenblas_func("cblas_scamin"); 
        if(_g_cblas_scamin==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_scamin(
        n,
        x,
        incx    
    );
}
