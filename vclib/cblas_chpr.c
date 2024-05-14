#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_chpr not found\n";
typedef void (CALLBACK* PFNcblas_chpr)( /* cblas_chpr */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST float            /* alpha */,
    OPENBLAS_CONST void *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    void *            /* A */
);
static PFNcblas_chpr _g_cblas_chpr = NULL;
void cblas_chpr(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST float            alpha,
    OPENBLAS_CONST void *            X,
    OPENBLAS_CONST blasint            incX,
    void *            A
)
{
    if(_g_cblas_chpr==NULL) {
        _g_cblas_chpr = rindow_load_libopenblas_func("cblas_chpr"); 
        if(_g_cblas_chpr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_chpr(
        order,
        Uplo,
        N,
        alpha,
        X,
        incX,
        A    
    );
}
