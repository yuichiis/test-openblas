#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_stpmv not found\n";
typedef void (CALLBACK* PFNcblas_stpmv)( /* cblas_stpmv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST enum CBLAS_DIAG            /* Diag */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST float *            /* Ap */,
    float *            /* X */,
    OPENBLAS_CONST blasint            /* incX */
);
static PFNcblas_stpmv _g_cblas_stpmv = NULL;
void cblas_stpmv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransA,
    OPENBLAS_CONST enum CBLAS_DIAG            Diag,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST float *            Ap,
    float *            X,
    OPENBLAS_CONST blasint            incX
)
{
    if(_g_cblas_stpmv==NULL) {
        _g_cblas_stpmv = rindow_load_libopenblas_func("cblas_stpmv"); 
        if(_g_cblas_stpmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_stpmv(
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
