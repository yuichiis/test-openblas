#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_stbmv not found\n";
typedef void (CALLBACK* PFNcblas_stbmv)( /* cblas_stbmv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST enum CBLAS_DIAG            /* Diag */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST blasint            /* K */,
    OPENBLAS_CONST float *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    float *            /* X */,
    OPENBLAS_CONST blasint            /* incX */
);
static PFNcblas_stbmv _g_cblas_stbmv = NULL;
void cblas_stbmv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransA,
    OPENBLAS_CONST enum CBLAS_DIAG            Diag,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST blasint            K,
    OPENBLAS_CONST float *            A,
    OPENBLAS_CONST blasint            lda,
    float *            X,
    OPENBLAS_CONST blasint            incX
)
{
    if(_g_cblas_stbmv==NULL) {
        _g_cblas_stbmv = rindow_load_libopenblas_func("cblas_stbmv"); 
        if(_g_cblas_stbmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_stbmv(
        order,
        Uplo,
        TransA,
        Diag,
        N,
        K,
        A,
        lda,
        X,
        incX    
    );
}
