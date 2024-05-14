#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_ssymv not found\n";
typedef void (CALLBACK* PFNcblas_ssymv)( /* cblas_ssymv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST float            /* alpha */,
    OPENBLAS_CONST float *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST float *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    OPENBLAS_CONST float            /* beta */,
    float *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */
);
static PFNcblas_ssymv _g_cblas_ssymv = NULL;
void cblas_ssymv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
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
    if(_g_cblas_ssymv==NULL) {
        _g_cblas_ssymv = rindow_load_libopenblas_func("cblas_ssymv"); 
        if(_g_cblas_ssymv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_ssymv(
        order,
        Uplo,
        N,
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
