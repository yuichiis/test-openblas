#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_drotm not found\n";
typedef void (CALLBACK* PFNcblas_drotm)( /* cblas_drotm */
    OPENBLAS_CONST blasint            /* N */,
    double *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    double *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */,
    OPENBLAS_CONST double *            /* P */
);
static PFNcblas_drotm _g_cblas_drotm = NULL;
void cblas_drotm(
    OPENBLAS_CONST blasint            N,
    double *            X,
    OPENBLAS_CONST blasint            incX,
    double *            Y,
    OPENBLAS_CONST blasint            incY,
    OPENBLAS_CONST double *            P
)
{
    if(_g_cblas_drotm==NULL) {
        _g_cblas_drotm = rindow_load_libopenblas_func("cblas_drotm"); 
        if(_g_cblas_drotm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_drotm(
        N,
        X,
        incX,
        Y,
        incY,
        P    
    );
}
