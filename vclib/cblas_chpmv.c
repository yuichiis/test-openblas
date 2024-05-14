#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_chpmv not found\n";
typedef void (CALLBACK* PFNcblas_chpmv)( /* cblas_chpmv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST void *            /* alpha */,
    OPENBLAS_CONST void *            /* Ap */,
    OPENBLAS_CONST void *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    OPENBLAS_CONST void *            /* beta */,
    void *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */
);
static PFNcblas_chpmv _g_cblas_chpmv = NULL;
void cblas_chpmv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST void *            alpha,
    OPENBLAS_CONST void *            Ap,
    OPENBLAS_CONST void *            X,
    OPENBLAS_CONST blasint            incX,
    OPENBLAS_CONST void *            beta,
    void *            Y,
    OPENBLAS_CONST blasint            incY
)
{
    if(_g_cblas_chpmv==NULL) {
        _g_cblas_chpmv = rindow_load_libopenblas_func("cblas_chpmv"); 
        if(_g_cblas_chpmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_chpmv(
        order,
        Uplo,
        N,
        alpha,
        Ap,
        X,
        incX,
        beta,
        Y,
        incY    
    );
}
