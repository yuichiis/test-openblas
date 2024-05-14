#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_sger not found\n";
typedef void (CALLBACK* PFNcblas_sger)( /* cblas_sger */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST blasint            /* M */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST float            /* alpha */,
    OPENBLAS_CONST float *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    OPENBLAS_CONST float *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */,
    float *            /* A */,
    OPENBLAS_CONST blasint            /* lda */
);
static PFNcblas_sger _g_cblas_sger = NULL;
void cblas_sger(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST blasint            M,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST float            alpha,
    OPENBLAS_CONST float *            X,
    OPENBLAS_CONST blasint            incX,
    OPENBLAS_CONST float *            Y,
    OPENBLAS_CONST blasint            incY,
    float *            A,
    OPENBLAS_CONST blasint            lda
)
{
    if(_g_cblas_sger==NULL) {
        _g_cblas_sger = rindow_load_libopenblas_func("cblas_sger"); 
        if(_g_cblas_sger==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_sger(
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
