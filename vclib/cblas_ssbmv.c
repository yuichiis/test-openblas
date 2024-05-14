#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_ssbmv not found\n";
typedef void (CALLBACK* PFNcblas_ssbmv)( /* cblas_ssbmv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST blasint            /* K */,
    OPENBLAS_CONST float            /* alpha */,
    OPENBLAS_CONST float *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST float *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    OPENBLAS_CONST float            /* beta */,
    float *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */
);
static PFNcblas_ssbmv _g_cblas_ssbmv = NULL;
void cblas_ssbmv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST blasint            K,
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
    if(_g_cblas_ssbmv==NULL) {
        _g_cblas_ssbmv = rindow_load_libopenblas_func("cblas_ssbmv"); 
        if(_g_cblas_ssbmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_ssbmv(
        order,
        Uplo,
        N,
        K,
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
