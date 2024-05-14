#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_isamin not found\n";
typedef CBLAS_INDEX (CALLBACK* PFNcblas_isamin)( /* cblas_isamin */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST float *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_isamin _g_cblas_isamin = NULL;
CBLAS_INDEX cblas_isamin(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST float *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_isamin==NULL) {
        _g_cblas_isamin = rindow_load_libopenblas_func("cblas_isamin"); 
        if(_g_cblas_isamin==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_isamin(
        n,
        x,
        incx    
    );
}
