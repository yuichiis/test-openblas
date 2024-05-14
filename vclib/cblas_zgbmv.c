#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_zgbmv not found\n";
typedef void (CALLBACK* PFNcblas_zgbmv)( /* cblas_zgbmv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST blasint            /* M */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST blasint            /* KL */,
    OPENBLAS_CONST blasint            /* KU */,
    OPENBLAS_CONST void *            /* alpha */,
    OPENBLAS_CONST void *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST void *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    OPENBLAS_CONST void *            /* beta */,
    void *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */
);
static PFNcblas_zgbmv _g_cblas_zgbmv = NULL;
void cblas_zgbmv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransA,
    OPENBLAS_CONST blasint            M,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST blasint            KL,
    OPENBLAS_CONST blasint            KU,
    OPENBLAS_CONST void *            alpha,
    OPENBLAS_CONST void *            A,
    OPENBLAS_CONST blasint            lda,
    OPENBLAS_CONST void *            X,
    OPENBLAS_CONST blasint            incX,
    OPENBLAS_CONST void *            beta,
    void *            Y,
    OPENBLAS_CONST blasint            incY
)
{
    if(_g_cblas_zgbmv==NULL) {
        _g_cblas_zgbmv = rindow_load_libopenblas_func("cblas_zgbmv"); 
        if(_g_cblas_zgbmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_zgbmv(
        order,
        TransA,
        M,
        N,
        KL,
        KU,
        alpha,
        A,
        lda,
        X,
        incX,
        beta,
        Y,
        incY    
    );
}
