#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_ssum not found\n";
typedef float (CALLBACK* PFNcblas_ssum)( /* cblas_ssum */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST float *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_ssum _g_cblas_ssum = NULL;
float cblas_ssum(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST float *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_ssum==NULL) {
        _g_cblas_ssum = rindow_load_libopenblas_func("cblas_ssum"); 
        if(_g_cblas_ssum==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_ssum(
        n,
        x,
        incx    
    );
}
