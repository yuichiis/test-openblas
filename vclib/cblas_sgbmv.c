#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_sgbmv not found\n";
typedef void (CALLBACK* PFNcblas_sgbmv)( /* cblas_sgbmv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST blasint            /* M */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST blasint            /* KL */,
    OPENBLAS_CONST blasint            /* KU */,
    OPENBLAS_CONST float            /* alpha */,
    OPENBLAS_CONST float *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST float *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    OPENBLAS_CONST float            /* beta */,
    float *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */
);
static PFNcblas_sgbmv _g_cblas_sgbmv = NULL;
void cblas_sgbmv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransA,
    OPENBLAS_CONST blasint            M,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST blasint            KL,
    OPENBLAS_CONST blasint            KU,
    OPENBLAS_CONST float            alpha,
    OPENBLAS_CONST float *            A,
    OPENBLAS_CONST blasint            lda,
    OPENBLAS_CONST float *            X,
    OPENBLAS_CONST blasint            incX,
    OPENBLAS_CONST float            beta,
    float *            Y,
    OPENBLAS_CONST blasint            incY
)
{
    if(_g_cblas_sgbmv==NULL) {
        _g_cblas_sgbmv = rindow_load_libopenblas_func("cblas_sgbmv"); 
        if(_g_cblas_sgbmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_sgbmv(
        order,
        TransA,
        M,
        N,
        KL,
        KU,
        alpha,
        A,
        lda,
        X,
        incX,
        beta,
        Y,
        incY    
    );
}
