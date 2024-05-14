#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_icmin not found\n";
typedef CBLAS_INDEX (CALLBACK* PFNcblas_icmin)( /* cblas_icmin */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_icmin _g_cblas_icmin = NULL;
CBLAS_INDEX cblas_icmin(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_icmin==NULL) {
        _g_cblas_icmin = rindow_load_libopenblas_func("cblas_icmin"); 
        if(_g_cblas_icmin==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_icmin(
        n,
        x,
        incx    
    );
}
