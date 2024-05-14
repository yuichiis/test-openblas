#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_chbmv not found\n";
typedef void (CALLBACK* PFNcblas_chbmv)( /* cblas_chbmv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST blasint            /* K */,
    OPENBLAS_CONST void *            /* alpha */,
    OPENBLAS_CONST void *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST void *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    OPENBLAS_CONST void *            /* beta */,
    void *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */
);
static PFNcblas_chbmv _g_cblas_chbmv = NULL;
void cblas_chbmv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST blasint            K,
    OPENBLAS_CONST void *            alpha,
    OPENBLAS_CONST void *            A,
    OPENBLAS_CONST blasint            lda,
    OPENBLAS_CONST void *            X,
    OPENBLAS_CONST blasint            incX,
    OPENBLAS_CONST void *            beta,
    void *            Y,
    OPENBLAS_CONST blasint            incY
)
{
    if(_g_cblas_chbmv==NULL) {
        _g_cblas_chbmv = rindow_load_libopenblas_func("cblas_chbmv"); 
        if(_g_cblas_chbmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_chbmv(
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
