#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_izamax not found\n";
typedef CBLAS_INDEX (CALLBACK* PFNcblas_izamax)( /* cblas_izamax */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_izamax _g_cblas_izamax = NULL;
CBLAS_INDEX cblas_izamax(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_izamax==NULL) {
        _g_cblas_izamax = rindow_load_libopenblas_func("cblas_izamax"); 
        if(_g_cblas_izamax==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_izamax(
        n,
        x,
        incx    
    );
}
