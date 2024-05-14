#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_ctpsv not found\n";
typedef void (CALLBACK* PFNcblas_ctpsv)( /* cblas_ctpsv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST enum CBLAS_DIAG            /* Diag */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST void *            /* Ap */,
    void *            /* X */,
    OPENBLAS_CONST blasint            /* incX */
);
static PFNcblas_ctpsv _g_cblas_ctpsv = NULL;
void cblas_ctpsv(
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
    if(_g_cblas_ctpsv==NULL) {
        _g_cblas_ctpsv = rindow_load_libopenblas_func("cblas_ctpsv"); 
        if(_g_cblas_ctpsv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_ctpsv(
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
