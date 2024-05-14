#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dtrmm not found\n";
typedef void (CALLBACK* PFNcblas_dtrmm)( /* cblas_dtrmm */
    OPENBLAS_CONST enum CBLAS_ORDER            /* Order */,
    OPENBLAS_CONST enum CBLAS_SIDE            /* Side */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST enum CBLAS_DIAG            /* Diag */,
    OPENBLAS_CONST blasint            /* M */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST double            /* alpha */,
    OPENBLAS_CONST double *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    double *            /* B */,
    OPENBLAS_CONST blasint            /* ldb */
);
static PFNcblas_dtrmm _g_cblas_dtrmm = NULL;
void cblas_dtrmm(
    OPENBLAS_CONST enum CBLAS_ORDER            Order,
    OPENBLAS_CONST enum CBLAS_SIDE            Side,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransA,
    OPENBLAS_CONST enum CBLAS_DIAG            Diag,
    OPENBLAS_CONST blasint            M,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST double            alpha,
    OPENBLAS_CONST double *            A,
    OPENBLAS_CONST blasint            lda,
    double *            B,
    OPENBLAS_CONST blasint            ldb
)
{
    if(_g_cblas_dtrmm==NULL) {
        _g_cblas_dtrmm = rindow_load_libopenblas_func("cblas_dtrmm"); 
        if(_g_cblas_dtrmm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dtrmm(
        Order,
        Side,
        Uplo,
        TransA,
        Diag,
        M,
        N,
        alpha,
        A,
        lda,
        B,
        ldb    
    );
}
