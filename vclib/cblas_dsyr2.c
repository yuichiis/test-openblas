#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dsyr2 not found\n";
typedef void (CALLBACK* PFNcblas_dsyr2)( /* cblas_dsyr2 */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST double            /* alpha */,
    OPENBLAS_CONST double *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    OPENBLAS_CONST double *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */,
    double *            /* A */,
    OPENBLAS_CONST blasint            /* lda */
);
static PFNcblas_dsyr2 _g_cblas_dsyr2 = NULL;
void cblas_dsyr2(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST double            alpha,
    OPENBLAS_CONST double *            X,
    OPENBLAS_CONST blasint            incX,
    OPENBLAS_CONST double *            Y,
    OPENBLAS_CONST blasint            incY,
    double *            A,
    OPENBLAS_CONST blasint            lda
)
{
    if(_g_cblas_dsyr2==NULL) {
        _g_cblas_dsyr2 = rindow_load_libopenblas_func("cblas_dsyr2"); 
        if(_g_cblas_dsyr2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dsyr2(
        order,
        Uplo,
        N,
        alpha,
        X,
        incX,
        Y,
        incY,
        A,
        lda    
    );
}
