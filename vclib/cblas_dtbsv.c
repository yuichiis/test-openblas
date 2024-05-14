#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dtbsv not found\n";
typedef void (CALLBACK* PFNcblas_dtbsv)( /* cblas_dtbsv */
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
static PFNcblas_dtbsv _g_cblas_dtbsv = NULL;
void cblas_dtbsv(
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
    if(_g_cblas_dtbsv==NULL) {
        _g_cblas_dtbsv = rindow_load_libopenblas_func("cblas_dtbsv"); 
        if(_g_cblas_dtbsv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dtbsv(
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
