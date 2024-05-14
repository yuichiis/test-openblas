#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_cher2k not found\n";
typedef void (CALLBACK* PFNcblas_cher2k)( /* cblas_cher2k */
    OPENBLAS_CONST enum CBLAS_ORDER            /* Order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* Trans */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST blasint            /* K */,
    OPENBLAS_CONST void *            /* alpha */,
    OPENBLAS_CONST void *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST void *            /* B */,
    OPENBLAS_CONST blasint            /* ldb */,
    OPENBLAS_CONST float            /* beta */,
    void *            /* C */,
    OPENBLAS_CONST blasint            /* ldc */
);
static PFNcblas_cher2k _g_cblas_cher2k = NULL;
void cblas_cher2k(
    OPENBLAS_CONST enum CBLAS_ORDER            Order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            Trans,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST blasint            K,
    OPENBLAS_CONST void *            alpha,
    OPENBLAS_CONST void *            A,
    OPENBLAS_CONST blasint            lda,
    OPENBLAS_CONST void *            B,
    OPENBLAS_CONST blasint            ldb,
    OPENBLAS_CONST float            beta,
    void *            C,
    OPENBLAS_CONST blasint            ldc
)
{
    if(_g_cblas_cher2k==NULL) {
        _g_cblas_cher2k = rindow_load_libopenblas_func("cblas_cher2k"); 
        if(_g_cblas_cher2k==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_cher2k(
        Order,
        Uplo,
        Trans,
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
