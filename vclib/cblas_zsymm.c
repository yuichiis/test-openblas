#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_zsymm not found\n";
typedef void (CALLBACK* PFNcblas_zsymm)( /* cblas_zsymm */
    OPENBLAS_CONST enum CBLAS_ORDER            /* Order */,
    OPENBLAS_CONST enum CBLAS_SIDE            /* Side */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* M */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST void *            /* alpha */,
    OPENBLAS_CONST void *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST void *            /* B */,
    OPENBLAS_CONST blasint            /* ldb */,
    OPENBLAS_CONST void *            /* beta */,
    void *            /* C */,
    OPENBLAS_CONST blasint            /* ldc */
);
static PFNcblas_zsymm _g_cblas_zsymm = NULL;
void cblas_zsymm(
    OPENBLAS_CONST enum CBLAS_ORDER            Order,
    OPENBLAS_CONST enum CBLAS_SIDE            Side,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            M,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST void *            alpha,
    OPENBLAS_CONST void *            A,
    OPENBLAS_CONST blasint            lda,
    OPENBLAS_CONST void *            B,
    OPENBLAS_CONST blasint            ldb,
    OPENBLAS_CONST void *            beta,
    void *            C,
    OPENBLAS_CONST blasint            ldc
)
{
    if(_g_cblas_zsymm==NULL) {
        _g_cblas_zsymm = rindow_load_libopenblas_func("cblas_zsymm"); 
        if(_g_cblas_zsymm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_zsymm(
        Order,
        Side,
        Uplo,
        M,
        N,
        alpha,
        A,
        lda,
        B,
        ldb,
        beta,
        C,
        ldc    
    );
}
