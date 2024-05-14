#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_sasum not found\n";
typedef float (CALLBACK* PFNcblas_sasum)( /* cblas_sasum */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST float *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_sasum _g_cblas_sasum = NULL;
float cblas_sasum(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST float *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_sasum==NULL) {
        _g_cblas_sasum = rindow_load_libopenblas_func("cblas_sasum"); 
        if(_g_cblas_sasum==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_sasum(
        n,
        x,
        incx    
    );
}
