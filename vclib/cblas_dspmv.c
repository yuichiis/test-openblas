#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dspmv not found\n";
typedef void (CALLBACK* PFNcblas_dspmv)( /* cblas_dspmv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST double            /* alpha */,
    OPENBLAS_CONST double *            /* Ap */,
    OPENBLAS_CONST double *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    OPENBLAS_CONST double            /* beta */,
    double *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */
);
static PFNcblas_dspmv _g_cblas_dspmv = NULL;
void cblas_dspmv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST double            alpha,
    OPENBLAS_CONST double *            Ap,
    OPENBLAS_CONST double *            X,
    OPENBLAS_CONST blasint            incX,
    OPENBLAS_CONST double            beta,
    double *            Y,
    OPENBLAS_CONST blasint            incY
)
{
    if(_g_cblas_dspmv==NULL) {
        _g_cblas_dspmv = rindow_load_libopenblas_func("cblas_dspmv"); 
        if(_g_cblas_dspmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dspmv(
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
