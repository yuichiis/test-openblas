#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dger not found\n";
typedef void (CALLBACK* PFNcblas_dger)( /* cblas_dger */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST blasint            /* M */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST double            /* alpha */,
    OPENBLAS_CONST double *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    OPENBLAS_CONST double *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */,
    double *            /* A */,
    OPENBLAS_CONST blasint            /* lda */
);
static PFNcblas_dger _g_cblas_dger = NULL;
void cblas_dger(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST blasint            M,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST double            alpha,
    OPENBLAS_CONST double *            X,
    OPENBLAS_CONST blasint            incX,
    OPENBLAS_CONST double *            Y,
    OPENBLAS_CONST blasint            incY,
    double *            A,
    OPENBLAS_CONST blasint            lda
)
{
    if(_g_cblas_dger==NULL) {
        _g_cblas_dger = rindow_load_libopenblas_func("cblas_dger"); 
        if(_g_cblas_dger==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dger(
        order,
        M,
        N,
        alpha,
        X,
        incX,
        Y,
        incY,
        A,
        lda    
    );
}
