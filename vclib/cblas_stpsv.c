#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_stpsv not found\n";
typedef void (CALLBACK* PFNcblas_stpsv)( /* cblas_stpsv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST enum CBLAS_DIAG            /* Diag */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST float *            /* Ap */,
    float *            /* X */,
    OPENBLAS_CONST blasint            /* incX */
);
static PFNcblas_stpsv _g_cblas_stpsv = NULL;
void cblas_stpsv(
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
    if(_g_cblas_stpsv==NULL) {
        _g_cblas_stpsv = rindow_load_libopenblas_func("cblas_stpsv"); 
        if(_g_cblas_stpsv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_stpsv(
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
