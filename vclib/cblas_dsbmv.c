#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dsbmv not found\n";
typedef void (CALLBACK* PFNcblas_dsbmv)( /* cblas_dsbmv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST blasint            /* K */,
    OPENBLAS_CONST double            /* alpha */,
    OPENBLAS_CONST double *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST double *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    OPENBLAS_CONST double            /* beta */,
    double *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */
);
static PFNcblas_dsbmv _g_cblas_dsbmv = NULL;
void cblas_dsbmv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST blasint            K,
    OPENBLAS_CONST double            alpha,
    OPENBLAS_CONST double *            A,
    OPENBLAS_CONST blasint            lda,
    OPENBLAS_CONST double *            X,
    OPENBLAS_CONST blasint            incX,
    OPENBLAS_CONST double            beta,
    double *            Y,
    OPENBLAS_CONST blasint            incY
)
{
    if(_g_cblas_dsbmv==NULL) {
        _g_cblas_dsbmv = rindow_load_libopenblas_func("cblas_dsbmv"); 
        if(_g_cblas_dsbmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dsbmv(
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
