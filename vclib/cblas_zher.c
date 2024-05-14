#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_zher not found\n";
typedef void (CALLBACK* PFNcblas_zher)( /* cblas_zher */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST double            /* alpha */,
    OPENBLAS_CONST void *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    void *            /* A */,
    OPENBLAS_CONST blasint            /* lda */
);
static PFNcblas_zher _g_cblas_zher = NULL;
void cblas_zher(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST double            alpha,
    OPENBLAS_CONST void *            X,
    OPENBLAS_CONST blasint            incX,
    void *            A,
    OPENBLAS_CONST blasint            lda
)
{
    if(_g_cblas_zher==NULL) {
        _g_cblas_zher = rindow_load_libopenblas_func("cblas_zher"); 
        if(_g_cblas_zher==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_zher(
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
