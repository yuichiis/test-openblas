#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_izmin not found\n";
typedef CBLAS_INDEX (CALLBACK* PFNcblas_izmin)( /* cblas_izmin */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_izmin _g_cblas_izmin = NULL;
CBLAS_INDEX cblas_izmin(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_izmin==NULL) {
        _g_cblas_izmin = rindow_load_libopenblas_func("cblas_izmin"); 
        if(_g_cblas_izmin==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_izmin(
        n,
        x,
        incx    
    );
}
