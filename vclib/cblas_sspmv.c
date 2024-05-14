#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_sspmv not found\n";
typedef void (CALLBACK* PFNcblas_sspmv)( /* cblas_sspmv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST float            /* alpha */,
    OPENBLAS_CONST float *            /* Ap */,
    OPENBLAS_CONST float *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    OPENBLAS_CONST float            /* beta */,
    float *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */
);
static PFNcblas_sspmv _g_cblas_sspmv = NULL;
void cblas_sspmv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST float            alpha,
    OPENBLAS_CONST float *            Ap,
    OPENBLAS_CONST float *            X,
    OPENBLAS_CONST blasint            incX,
    OPENBLAS_CONST float            beta,
    float *            Y,
    OPENBLAS_CONST blasint            incY
)
{
    if(_g_cblas_sspmv==NULL) {
        _g_cblas_sspmv = rindow_load_libopenblas_func("cblas_sspmv"); 
        if(_g_cblas_sspmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_sspmv(
        order,
        Uplo,
        N,
        alpha,
        Ap,
        X,
        incX,
        beta,
        Y,
        incY    
    );
}
