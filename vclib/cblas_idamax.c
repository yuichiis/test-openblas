#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_idamax not found\n";
typedef CBLAS_INDEX (CALLBACK* PFNcblas_idamax)( /* cblas_idamax */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST double *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_idamax _g_cblas_idamax = NULL;
CBLAS_INDEX cblas_idamax(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST double *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_idamax==NULL) {
        _g_cblas_idamax = rindow_load_libopenblas_func("cblas_idamax"); 
        if(_g_cblas_idamax==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_idamax(
        n,
        x,
        incx    
    );
}
