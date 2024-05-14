#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_cher2 not found\n";
typedef void (CALLBACK* PFNcblas_cher2)( /* cblas_cher2 */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST void *            /* alpha */,
    OPENBLAS_CONST void *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    OPENBLAS_CONST void *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */,
    void *            /* A */,
    OPENBLAS_CONST blasint            /* lda */
);
static PFNcblas_cher2 _g_cblas_cher2 = NULL;
void cblas_cher2(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST void *            alpha,
    OPENBLAS_CONST void *            X,
    OPENBLAS_CONST blasint            incX,
    OPENBLAS_CONST void *            Y,
    OPENBLAS_CONST blasint            incY,
    void *            A,
    OPENBLAS_CONST blasint            lda
)
{
    if(_g_cblas_cher2==NULL) {
        _g_cblas_cher2 = rindow_load_libopenblas_func("cblas_cher2"); 
        if(_g_cblas_cher2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_cher2(
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
