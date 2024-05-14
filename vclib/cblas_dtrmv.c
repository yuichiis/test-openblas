#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dtrmv not found\n";
typedef void (CALLBACK* PFNcblas_dtrmv)( /* cblas_dtrmv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST enum CBLAS_DIAG            /* Diag */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST double *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    double *            /* X */,
    OPENBLAS_CONST blasint            /* incX */
);
static PFNcblas_dtrmv _g_cblas_dtrmv = NULL;
void cblas_dtrmv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransA,
    OPENBLAS_CONST enum CBLAS_DIAG            Diag,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST double *            A,
    OPENBLAS_CONST blasint            lda,
    double *            X,
    OPENBLAS_CONST blasint            incX
)
{
    if(_g_cblas_dtrmv==NULL) {
        _g_cblas_dtrmv = rindow_load_libopenblas_func("cblas_dtrmv"); 
        if(_g_cblas_dtrmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dtrmv(
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
