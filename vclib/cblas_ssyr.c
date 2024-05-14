#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_ssyr not found\n";
typedef void (CALLBACK* PFNcblas_ssyr)( /* cblas_ssyr */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST float            /* alpha */,
    OPENBLAS_CONST float *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    float *            /* A */,
    OPENBLAS_CONST blasint            /* lda */
);
static PFNcblas_ssyr _g_cblas_ssyr = NULL;
void cblas_ssyr(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST float            alpha,
    OPENBLAS_CONST float *            X,
    OPENBLAS_CONST blasint            incX,
    float *            A,
    OPENBLAS_CONST blasint            lda
)
{
    if(_g_cblas_ssyr==NULL) {
        _g_cblas_ssyr = rindow_load_libopenblas_func("cblas_ssyr"); 
        if(_g_cblas_ssyr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_ssyr(
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
