#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_ctrmv not found\n";
typedef void (CALLBACK* PFNcblas_ctrmv)( /* cblas_ctrmv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST enum CBLAS_DIAG            /* Diag */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST void *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    void *            /* X */,
    OPENBLAS_CONST blasint            /* incX */
);
static PFNcblas_ctrmv _g_cblas_ctrmv = NULL;
void cblas_ctrmv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransA,
    OPENBLAS_CONST enum CBLAS_DIAG            Diag,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST void *            A,
    OPENBLAS_CONST blasint            lda,
    void *            X,
    OPENBLAS_CONST blasint            incX
)
{
    if(_g_cblas_ctrmv==NULL) {
        _g_cblas_ctrmv = rindow_load_libopenblas_func("cblas_ctrmv"); 
        if(_g_cblas_ctrmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_ctrmv(
        order,
        Uplo,
        TransA,
        Diag,
        N,
        A,
        lda,
        X,
        incX    
    );
}
