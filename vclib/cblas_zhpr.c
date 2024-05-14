#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_zhpr not found\n";
typedef void (CALLBACK* PFNcblas_zhpr)( /* cblas_zhpr */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST double            /* alpha */,
    OPENBLAS_CONST void *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    void *            /* A */
);
static PFNcblas_zhpr _g_cblas_zhpr = NULL;
void cblas_zhpr(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST double            alpha,
    OPENBLAS_CONST void *            X,
    OPENBLAS_CONST blasint            incX,
    void *            A
)
{
    if(_g_cblas_zhpr==NULL) {
        _g_cblas_zhpr = rindow_load_libopenblas_func("cblas_zhpr"); 
        if(_g_cblas_zhpr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_zhpr(
        order,
        Uplo,
        N,
        alpha,
        X,
        incX,
        A    
    );
}
