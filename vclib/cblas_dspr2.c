#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dspr2 not found\n";
typedef void (CALLBACK* PFNcblas_dspr2)( /* cblas_dspr2 */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST double            /* alpha */,
    OPENBLAS_CONST double *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    OPENBLAS_CONST double *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */,
    double *            /* A */
);
static PFNcblas_dspr2 _g_cblas_dspr2 = NULL;
void cblas_dspr2(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST double            alpha,
    OPENBLAS_CONST double *            X,
    OPENBLAS_CONST blasint            incX,
    OPENBLAS_CONST double *            Y,
    OPENBLAS_CONST blasint            incY,
    double *            A
)
{
    if(_g_cblas_dspr2==NULL) {
        _g_cblas_dspr2 = rindow_load_libopenblas_func("cblas_dspr2"); 
        if(_g_cblas_dspr2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dspr2(
        order,
        Uplo,
        N,
        alpha,
        X,
        incX,
        Y,
        incY,
        A    
    );
}
