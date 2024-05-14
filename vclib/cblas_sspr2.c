#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_sspr2 not found\n";
typedef void (CALLBACK* PFNcblas_sspr2)( /* cblas_sspr2 */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST float            /* alpha */,
    OPENBLAS_CONST float *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    OPENBLAS_CONST float *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */,
    float *            /* A */
);
static PFNcblas_sspr2 _g_cblas_sspr2 = NULL;
void cblas_sspr2(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST float            alpha,
    OPENBLAS_CONST float *            X,
    OPENBLAS_CONST blasint            incX,
    OPENBLAS_CONST float *            Y,
    OPENBLAS_CONST blasint            incY,
    float *            A
)
{
    if(_g_cblas_sspr2==NULL) {
        _g_cblas_sspr2 = rindow_load_libopenblas_func("cblas_sspr2"); 
        if(_g_cblas_sspr2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_sspr2(
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
