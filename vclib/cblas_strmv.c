#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_strmv not found\n";
typedef void (CALLBACK* PFNcblas_strmv)( /* cblas_strmv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST enum CBLAS_DIAG            /* Diag */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST float *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    float *            /* X */,
    OPENBLAS_CONST blasint            /* incX */
);
static PFNcblas_strmv _g_cblas_strmv = NULL;
void cblas_strmv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransA,
    OPENBLAS_CONST enum CBLAS_DIAG            Diag,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST float *            A,
    OPENBLAS_CONST blasint            lda,
    float *            X,
    OPENBLAS_CONST blasint            incX
)
{
    if(_g_cblas_strmv==NULL) {
        _g_cblas_strmv = rindow_load_libopenblas_func("cblas_strmv"); 
        if(_g_cblas_strmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_strmv(
        order,
        Uplo,
        TransA,
        Diag,
        N,
        A,
        lda,
        X,
        incX    
    );
}
