#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_saxpby not found\n";
typedef void (CALLBACK* PFNcblas_saxpby)( /* cblas_saxpby */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST float            /* alpha */,
    OPENBLAS_CONST float *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    OPENBLAS_CONST float            /* beta */,
    float *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_saxpby _g_cblas_saxpby = NULL;
void cblas_saxpby(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST float            alpha,
    OPENBLAS_CONST float *            x,
    OPENBLAS_CONST blasint            incx,
    OPENBLAS_CONST float            beta,
    float *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_saxpby==NULL) {
        _g_cblas_saxpby = rindow_load_libopenblas_func("cblas_saxpby"); 
        if(_g_cblas_saxpby==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_saxpby(
        n,
        alpha,
        x,
        incx,
        beta,
        y,
        incy    
    );
}
