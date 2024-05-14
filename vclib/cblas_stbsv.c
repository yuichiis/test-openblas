#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_stbsv not found\n";
typedef void (CALLBACK* PFNcblas_stbsv)( /* cblas_stbsv */
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
static PFNcblas_stbsv _g_cblas_stbsv = NULL;
void cblas_stbsv(
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
    if(_g_cblas_stbsv==NULL) {
        _g_cblas_stbsv = rindow_load_libopenblas_func("cblas_stbsv"); 
        if(_g_cblas_stbsv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_stbsv(
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
