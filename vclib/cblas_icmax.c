#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_icmax not found\n";
typedef CBLAS_INDEX (CALLBACK* PFNcblas_icmax)( /* cblas_icmax */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_icmax _g_cblas_icmax = NULL;
CBLAS_INDEX cblas_icmax(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_icmax==NULL) {
        _g_cblas_icmax = rindow_load_libopenblas_func("cblas_icmax"); 
        if(_g_cblas_icmax==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_icmax(
        n,
        x,
        incx    
    );
}
