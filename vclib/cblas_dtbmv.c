#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dtbmv not found\n";
typedef void (CALLBACK* PFNcblas_dtbmv)( /* cblas_dtbmv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST enum CBLAS_DIAG            /* Diag */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST blasint            /* K */,
    OPENBLAS_CONST double *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    double *            /* X */,
    OPENBLAS_CONST blasint            /* incX */
);
static PFNcblas_dtbmv _g_cblas_dtbmv = NULL;
void cblas_dtbmv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransA,
    OPENBLAS_CONST enum CBLAS_DIAG            Diag,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST blasint            K,
    OPENBLAS_CONST double *            A,
    OPENBLAS_CONST blasint            lda,
    double *            X,
    OPENBLAS_CONST blasint            incX
)
{
    if(_g_cblas_dtbmv==NULL) {
        _g_cblas_dtbmv = rindow_load_libopenblas_func("cblas_dtbmv"); 
        if(_g_cblas_dtbmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dtbmv(
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
