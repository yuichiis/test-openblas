#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_cgemm not found\n";
typedef void (CALLBACK* PFNcblas_cgemm)( /* cblas_cgemm */
    OPENBLAS_CONST enum CBLAS_ORDER            /* Order */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransB */,
    OPENBLAS_CONST blasint            /* M */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST blasint            /* K */,
    OPENBLAS_CONST void *            /* alpha */,
    OPENBLAS_CONST void *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST void *            /* B */,
    OPENBLAS_CONST blasint            /* ldb */,
    OPENBLAS_CONST void *            /* beta */,
    void *            /* C */,
    OPENBLAS_CONST blasint            /* ldc */
);
static PFNcblas_cgemm _g_cblas_cgemm = NULL;
void cblas_cgemm(
    OPENBLAS_CONST enum CBLAS_ORDER            Order,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransA,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransB,
    OPENBLAS_CONST blasint            M,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST blasint            K,
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
    if(_g_cblas_cgemm==NULL) {
        _g_cblas_cgemm = rindow_load_libopenblas_func("cblas_cgemm"); 
        if(_g_cblas_cgemm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_cgemm(
        Order,
        TransA,
        TransB,
        M,
        N,
        K,
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
