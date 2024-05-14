#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dzamin not found\n";
typedef double (CALLBACK* PFNcblas_dzamin)( /* cblas_dzamin */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_dzamin _g_cblas_dzamin = NULL;
double cblas_dzamin(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_dzamin==NULL) {
        _g_cblas_dzamin = rindow_load_libopenblas_func("cblas_dzamin"); 
        if(_g_cblas_dzamin==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_dzamin(
        n,
        x,
        incx    
    );
}
