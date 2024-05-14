#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_zgeru not found\n";
typedef void (CALLBACK* PFNcblas_zgeru)( /* cblas_zgeru */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST blasint            /* M */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST void *            /* alpha */,
    OPENBLAS_CONST void *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    OPENBLAS_CONST void *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */,
    void *            /* A */,
    OPENBLAS_CONST blasint            /* lda */
);
static PFNcblas_zgeru _g_cblas_zgeru = NULL;
void cblas_zgeru(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST blasint            M,
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
    if(_g_cblas_zgeru==NULL) {
        _g_cblas_zgeru = rindow_load_libopenblas_func("cblas_zgeru"); 
        if(_g_cblas_zgeru==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_zgeru(
        order,
        M,
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
