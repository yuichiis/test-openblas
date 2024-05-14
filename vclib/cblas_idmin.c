#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_idmin not found\n";
typedef CBLAS_INDEX (CALLBACK* PFNcblas_idmin)( /* cblas_idmin */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST double *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_idmin _g_cblas_idmin = NULL;
CBLAS_INDEX cblas_idmin(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST double *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_idmin==NULL) {
        _g_cblas_idmin = rindow_load_libopenblas_func("cblas_idmin"); 
        if(_g_cblas_idmin==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_idmin(
        n,
        x,
        incx    
    );
}
