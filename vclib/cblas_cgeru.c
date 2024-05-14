#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_cgeru not found\n";
typedef void (CALLBACK* PFNcblas_cgeru)( /* cblas_cgeru */
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
static PFNcblas_cgeru _g_cblas_cgeru = NULL;
void cblas_cgeru(
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
    if(_g_cblas_cgeru==NULL) {
        _g_cblas_cgeru = rindow_load_libopenblas_func("cblas_cgeru"); 
        if(_g_cblas_cgeru==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_cgeru(
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
