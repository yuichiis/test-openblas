#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_srotm not found\n";
typedef void (CALLBACK* PFNcblas_srotm)( /* cblas_srotm */
    OPENBLAS_CONST blasint            /* N */,
    float *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    float *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */,
    OPENBLAS_CONST float *            /* P */
);
static PFNcblas_srotm _g_cblas_srotm = NULL;
void cblas_srotm(
    OPENBLAS_CONST blasint            N,
    float *            X,
    OPENBLAS_CONST blasint            incX,
    float *            Y,
    OPENBLAS_CONST blasint            incY,
    OPENBLAS_CONST float *            P
)
{
    if(_g_cblas_srotm==NULL) {
        _g_cblas_srotm = rindow_load_libopenblas_func("cblas_srotm"); 
        if(_g_cblas_srotm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_srotm(
        N,
        X,
        incX,
        Y,
        incY,
        P    
    );
}
