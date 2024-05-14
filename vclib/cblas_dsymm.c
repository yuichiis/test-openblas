#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dsymm not found\n";
typedef void (CALLBACK* PFNcblas_dsymm)( /* cblas_dsymm */
    OPENBLAS_CONST enum CBLAS_ORDER            /* Order */,
    OPENBLAS_CONST enum CBLAS_SIDE            /* Side */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* M */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST double            /* alpha */,
    OPENBLAS_CONST double *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST double *            /* B */,
    OPENBLAS_CONST blasint            /* ldb */,
    OPENBLAS_CONST double            /* beta */,
    double *            /* C */,
    OPENBLAS_CONST blasint            /* ldc */
);
static PFNcblas_dsymm _g_cblas_dsymm = NULL;
void cblas_dsymm(
    OPENBLAS_CONST enum CBLAS_ORDER            Order,
    OPENBLAS_CONST enum CBLAS_SIDE            Side,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            M,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST double            alpha,
    OPENBLAS_CONST double *            A,
    OPENBLAS_CONST blasint            lda,
    OPENBLAS_CONST double *            B,
    OPENBLAS_CONST blasint            ldb,
    OPENBLAS_CONST double            beta,
    double *            C,
    OPENBLAS_CONST blasint            ldc
)
{
    if(_g_cblas_dsymm==NULL) {
        _g_cblas_dsymm = rindow_load_libopenblas_func("cblas_dsymm"); 
        if(_g_cblas_dsymm==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dsymm(
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
