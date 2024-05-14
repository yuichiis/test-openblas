#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_ssymm not found\n";
typedef void (CALLBACK* PFNcblas_ssymm)( /* cblas_ssymm */
    OPENBLAS_CONST enum CBLAS_ORDER            /* Order */,
    OPENBLAS_CONST enum CBLAS_SIDE            /* Side */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* M */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST float            /* alpha */,
    OPENBLAS_CONST float *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST float *            /* B */,
    OPENBLAS_CONST blasint            /* ldb */,
    OPENBLAS_CONST float            /* beta */,
    float *            /* C */,
    OPENBLAS_CONST blasint            /* ldc */
);
static PFNcblas_ssymm _g_cblas_ssymm = NULL;
void cblas_ssymm(
    OPENBLAS_CONST enum CBLAS_ORDER            Order,
    OPENBLAS_CONST enum CBLAS_SIDE            Side,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            M,
    OPENBLAS_CONST blasint            N,
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
    if(_g_cblas_ssymm==NULL) {
        _g_cblas_ssymm = rindow_load_libopenblas_func("cblas_ssymm"); 
        if(_g_cblas_ssymm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_ssymm(
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
