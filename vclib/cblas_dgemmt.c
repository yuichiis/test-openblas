#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dgemmt not found\n";
typedef void (CALLBACK* PFNcblas_dgemmt)( /* cblas_dgemmt */
    OPENBLAS_CONST enum CBLAS_ORDER            /* Order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransB */,
    OPENBLAS_CONST blasint            /* M */,
    OPENBLAS_CONST blasint            /* K */,
    OPENBLAS_CONST double            /* alpha */,
    OPENBLAS_CONST double *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST double *            /* B */,
    OPENBLAS_CONST blasint            /* ldb */,
    OPENBLAS_CONST double            /* beta */,
    double *            /* C */,
    OPENBLAS_CONST blasint            /* ldc */
);
static PFNcblas_dgemmt _g_cblas_dgemmt = NULL;
void cblas_dgemmt(
    OPENBLAS_CONST enum CBLAS_ORDER            Order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransA,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransB,
    OPENBLAS_CONST blasint            M,
    OPENBLAS_CONST blasint            K,
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
    if(_g_cblas_dgemmt==NULL) {
        _g_cblas_dgemmt = rindow_load_libopenblas_func("cblas_dgemmt"); 
        if(_g_cblas_dgemmt==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dgemmt(
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
