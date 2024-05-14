#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dtpmv not found\n";
typedef void (CALLBACK* PFNcblas_dtpmv)( /* cblas_dtpmv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST enum CBLAS_DIAG            /* Diag */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST double *            /* Ap */,
    double *            /* X */,
    OPENBLAS_CONST blasint            /* incX */
);
static PFNcblas_dtpmv _g_cblas_dtpmv = NULL;
void cblas_dtpmv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransA,
    OPENBLAS_CONST enum CBLAS_DIAG            Diag,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST double *            Ap,
    double *            X,
    OPENBLAS_CONST blasint            incX
)
{
    if(_g_cblas_dtpmv==NULL) {
        _g_cblas_dtpmv = rindow_load_libopenblas_func("cblas_dtpmv"); 
        if(_g_cblas_dtpmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dtpmv(
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
