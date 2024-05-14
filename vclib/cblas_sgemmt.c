#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_sgemmt not found\n";
typedef void (CALLBACK* PFNcblas_sgemmt)( /* cblas_sgemmt */
    OPENBLAS_CONST enum CBLAS_ORDER            /* Order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransB */,
    OPENBLAS_CONST blasint            /* M */,
    OPENBLAS_CONST blasint            /* K */,
    OPENBLAS_CONST float            /* alpha */,
    OPENBLAS_CONST float *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST float *            /* B */,
    OPENBLAS_CONST blasint            /* ldb */,
    OPENBLAS_CONST float            /* beta */,
    float *            /* C */,
    OPENBLAS_CONST blasint            /* ldc */
);
static PFNcblas_sgemmt _g_cblas_sgemmt = NULL;
void cblas_sgemmt(
    OPENBLAS_CONST enum CBLAS_ORDER            Order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransA,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransB,
    OPENBLAS_CONST blasint            M,
    OPENBLAS_CONST blasint            K,
    OPENBLAS_CONST float            alpha,
    OPENBLAS_CONST float *            A,
    OPENBLAS_CONST blasint            lda,
    OPENBLAS_CONST float *            B,
    OPENBLAS_CONST blasint            ldb,
    OPENBLAS_CONST float            beta,
    float *            C,
    OPENBLAS_CONST blasint            ldc
)
{
    if(_g_cblas_sgemmt==NULL) {
        _g_cblas_sgemmt = rindow_load_libopenblas_func("cblas_sgemmt"); 
        if(_g_cblas_sgemmt==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_sgemmt(
        Order,
        Uplo,
        TransA,
        TransB,
        M,
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
