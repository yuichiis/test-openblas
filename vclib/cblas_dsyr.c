#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dsyr not found\n";
typedef void (CALLBACK* PFNcblas_dsyr)( /* cblas_dsyr */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST double            /* alpha */,
    OPENBLAS_CONST double *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    double *            /* A */,
    OPENBLAS_CONST blasint            /* lda */
);
static PFNcblas_dsyr _g_cblas_dsyr = NULL;
void cblas_dsyr(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST double            alpha,
    OPENBLAS_CONST double *            X,
    OPENBLAS_CONST blasint            incX,
    double *            A,
    OPENBLAS_CONST blasint            lda
)
{
    if(_g_cblas_dsyr==NULL) {
        _g_cblas_dsyr = rindow_load_libopenblas_func("cblas_dsyr"); 
        if(_g_cblas_dsyr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dsyr(
        order,
        Uplo,
        N,
        alpha,
        X,
        incX,
        A,
        lda    
    );
}
