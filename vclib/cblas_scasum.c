#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_scasum not found\n";
typedef float (CALLBACK* PFNcblas_scasum)( /* cblas_scasum */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_scasum _g_cblas_scasum = NULL;
float cblas_scasum(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_scasum==NULL) {
        _g_cblas_scasum = rindow_load_libopenblas_func("cblas_scasum"); 
        if(_g_cblas_scasum==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_scasum(
        n,
        x,
        incx    
    );
}
