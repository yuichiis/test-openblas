#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dzamax not found\n";
typedef double (CALLBACK* PFNcblas_dzamax)( /* cblas_dzamax */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_dzamax _g_cblas_dzamax = NULL;
double cblas_dzamax(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_dzamax==NULL) {
        _g_cblas_dzamax = rindow_load_libopenblas_func("cblas_dzamax"); 
        if(_g_cblas_dzamax==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_dzamax(
        n,
        x,
        incx    
    );
}
