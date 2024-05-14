#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dspr not found\n";
typedef void (CALLBACK* PFNcblas_dspr)( /* cblas_dspr */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST double            /* alpha */,
    OPENBLAS_CONST double *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    double *            /* Ap */
);
static PFNcblas_dspr _g_cblas_dspr = NULL;
void cblas_dspr(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST double            alpha,
    OPENBLAS_CONST double *            X,
    OPENBLAS_CONST blasint            incX,
    double *            Ap
)
{
    if(_g_cblas_dspr==NULL) {
        _g_cblas_dspr = rindow_load_libopenblas_func("cblas_dspr"); 
        if(_g_cblas_dspr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dspr(
        order,
        Uplo,
        N,
        alpha,
        X,
        incX,
        Ap    
    );
}
