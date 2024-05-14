#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_ctrmm not found\n";
typedef void (CALLBACK* PFNcblas_ctrmm)( /* cblas_ctrmm */
    OPENBLAS_CONST enum CBLAS_ORDER            /* Order */,
    OPENBLAS_CONST enum CBLAS_SIDE            /* Side */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST enum CBLAS_DIAG            /* Diag */,
    OPENBLAS_CONST blasint            /* M */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST void *            /* alpha */,
    OPENBLAS_CONST void *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    void *            /* B */,
    OPENBLAS_CONST blasint            /* ldb */
);
static PFNcblas_ctrmm _g_cblas_ctrmm = NULL;
void cblas_ctrmm(
    OPENBLAS_CONST enum CBLAS_ORDER            Order,
    OPENBLAS_CONST enum CBLAS_SIDE            Side,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransA,
    OPENBLAS_CONST enum CBLAS_DIAG            Diag,
    OPENBLAS_CONST blasint            M,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST void *            alpha,
    OPENBLAS_CONST void *            A,
    OPENBLAS_CONST blasint            lda,
    void *            B,
    OPENBLAS_CONST blasint            ldb
)
{
    if(_g_cblas_ctrmm==NULL) {
        _g_cblas_ctrmm = rindow_load_libopenblas_func("cblas_ctrmm"); 
        if(_g_cblas_ctrmm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_ctrmm(
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
