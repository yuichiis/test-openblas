#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_sspr not found\n";
typedef void (CALLBACK* PFNcblas_sspr)( /* cblas_sspr */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST float            /* alpha */,
    OPENBLAS_CONST float *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    float *            /* Ap */
);
static PFNcblas_sspr _g_cblas_sspr = NULL;
void cblas_sspr(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST float            alpha,
    OPENBLAS_CONST float *            X,
    OPENBLAS_CONST blasint            incX,
    float *            Ap
)
{
    if(_g_cblas_sspr==NULL) {
        _g_cblas_sspr = rindow_load_libopenblas_func("cblas_sspr"); 
        if(_g_cblas_sspr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_sspr(
        order,
        Uplo,
        N,
        alpha,
        X,
        incX,
        Ap    
    );
}
