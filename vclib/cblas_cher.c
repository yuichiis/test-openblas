#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_cher not found\n";
typedef void (CALLBACK* PFNcblas_cher)( /* cblas_cher */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST float            /* alpha */,
    OPENBLAS_CONST void *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    void *            /* A */,
    OPENBLAS_CONST blasint            /* lda */
);
static PFNcblas_cher _g_cblas_cher = NULL;
void cblas_cher(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST float            alpha,
    OPENBLAS_CONST void *            X,
    OPENBLAS_CONST blasint            incX,
    void *            A,
    OPENBLAS_CONST blasint            lda
)
{
    if(_g_cblas_cher==NULL) {
        _g_cblas_cher = rindow_load_libopenblas_func("cblas_cher"); 
        if(_g_cblas_cher==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_cher(
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
