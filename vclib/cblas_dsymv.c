#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dsymv not found\n";
typedef void (CALLBACK* PFNcblas_dsymv)( /* cblas_dsymv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST double            /* alpha */,
    OPENBLAS_CONST double *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST double *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    OPENBLAS_CONST double            /* beta */,
    double *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */
);
static PFNcblas_dsymv _g_cblas_dsymv = NULL;
void cblas_dsymv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
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
    if(_g_cblas_dsymv==NULL) {
        _g_cblas_dsymv = rindow_load_libopenblas_func("cblas_dsymv"); 
        if(_g_cblas_dsymv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dsymv(
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
