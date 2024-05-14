#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_zhpr2 not found\n";
typedef void (CALLBACK* PFNcblas_zhpr2)( /* cblas_zhpr2 */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST void *            /* alpha */,
    OPENBLAS_CONST void *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    OPENBLAS_CONST void *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */,
    void *            /* Ap */
);
static PFNcblas_zhpr2 _g_cblas_zhpr2 = NULL;
void cblas_zhpr2(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST void *            alpha,
    OPENBLAS_CONST void *            X,
    OPENBLAS_CONST blasint            incX,
    OPENBLAS_CONST void *            Y,
    OPENBLAS_CONST blasint            incY,
    void *            Ap
)
{
    if(_g_cblas_zhpr2==NULL) {
        _g_cblas_zhpr2 = rindow_load_libopenblas_func("cblas_zhpr2"); 
        if(_g_cblas_zhpr2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_zhpr2(
        order,
        Uplo,
        N,
        alpha,
        X,
        incX,
        Y,
        incY,
        Ap    
    );
}
