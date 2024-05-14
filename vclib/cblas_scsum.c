#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_scsum not found\n";
typedef float (CALLBACK* PFNcblas_scsum)( /* cblas_scsum */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_scsum _g_cblas_scsum = NULL;
float cblas_scsum(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_scsum==NULL) {
        _g_cblas_scsum = rindow_load_libopenblas_func("cblas_scsum"); 
        if(_g_cblas_scsum==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_scsum(
        n,
        x,
        incx    
    );
}
