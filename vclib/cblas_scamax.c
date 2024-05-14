#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_scamax not found\n";
typedef float (CALLBACK* PFNcblas_scamax)( /* cblas_scamax */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_scamax _g_cblas_scamax = NULL;
float cblas_scamax(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_scamax==NULL) {
        _g_cblas_scamax = rindow_load_libopenblas_func("cblas_scamax"); 
        if(_g_cblas_scamax==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_scamax(
        n,
        x,
        incx    
    );
}
