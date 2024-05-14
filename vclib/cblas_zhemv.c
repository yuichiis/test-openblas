#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_zhemv not found\n";
typedef void (CALLBACK* PFNcblas_zhemv)( /* cblas_zhemv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST void *            /* alpha */,
    OPENBLAS_CONST void *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST void *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    OPENBLAS_CONST void *            /* beta */,
    void *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */
);
static PFNcblas_zhemv _g_cblas_zhemv = NULL;
void cblas_zhemv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
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
    if(_g_cblas_zhemv==NULL) {
        _g_cblas_zhemv = rindow_load_libopenblas_func("cblas_zhemv"); 
        if(_g_cblas_zhemv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_zhemv(
        order,
        Uplo,
        N,
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
