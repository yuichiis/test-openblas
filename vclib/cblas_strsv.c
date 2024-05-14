#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_strsv not found\n";
typedef void (CALLBACK* PFNcblas_strsv)( /* cblas_strsv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_UPLO            /* Uplo */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST enum CBLAS_DIAG            /* Diag */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST float *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    float *            /* X */,
    OPENBLAS_CONST blasint            /* incX */
);
static PFNcblas_strsv _g_cblas_strsv = NULL;
void cblas_strsv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_UPLO            Uplo,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransA,
    OPENBLAS_CONST enum CBLAS_DIAG            Diag,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST float *            A,
    OPENBLAS_CONST blasint            lda,
    float *            X,
    OPENBLAS_CONST blasint            incX
)
{
    if(_g_cblas_strsv==NULL) {
        _g_cblas_strsv = rindow_load_libopenblas_func("cblas_strsv"); 
        if(_g_cblas_strsv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_strsv(
        order,
        Uplo,
        TransA,
        Diag,
        N,
        A,
        lda,
        X,
        incX    
    );
}
