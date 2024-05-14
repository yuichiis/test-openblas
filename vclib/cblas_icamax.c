#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_icamax not found\n";
typedef CBLAS_INDEX (CALLBACK* PFNcblas_icamax)( /* cblas_icamax */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_icamax _g_cblas_icamax = NULL;
CBLAS_INDEX cblas_icamax(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_icamax==NULL) {
        _g_cblas_icamax = rindow_load_libopenblas_func("cblas_icamax"); 
        if(_g_cblas_icamax==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_icamax(
        n,
        x,
        incx    
    );
}
