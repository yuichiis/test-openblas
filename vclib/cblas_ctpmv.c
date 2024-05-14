#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_ctpmv not found\n";
typedef void (CALLBACK* PFNcblas_ctpmv)( /* cblas_ctpmv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST enum CBLAS_DIAG            /* Diag */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST void *            /* Ap */,
    void *            /* X */,
    OPENBLAS_CONST blasint            /* incX */
);
static PFNcblas_ctpmv _g_cblas_ctpmv = NULL;
void cblas_ctpmv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransA,
    OPENBLAS_CONST enum CBLAS_DIAG            Diag,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST void *            Ap,
    void *            X,
    OPENBLAS_CONST blasint            incX
)
{
    if(_g_cblas_ctpmv==NULL) {
        _g_cblas_ctpmv = rindow_load_libopenblas_func("cblas_ctpmv"); 
        if(_g_cblas_ctpmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_ctpmv(
        order,
        Uplo,
        TransA,
        Diag,
        N,
        Ap,
        X,
        incX    
    );
}
