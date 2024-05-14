#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_idamin not found\n";
typedef CBLAS_INDEX (CALLBACK* PFNcblas_idamin)( /* cblas_idamin */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST double *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_idamin _g_cblas_idamin = NULL;
CBLAS_INDEX cblas_idamin(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST double *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_idamin==NULL) {
        _g_cblas_idamin = rindow_load_libopenblas_func("cblas_idamin"); 
        if(_g_cblas_idamin==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_idamin(
        n,
        x,
        incx    
    );
}
