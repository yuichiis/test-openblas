#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dgbmv not found\n";
typedef void (CALLBACK* PFNcblas_dgbmv)( /* cblas_dgbmv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* TransA */,
    OPENBLAS_CONST blasint            /* M */,
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST blasint            /* KL */,
    OPENBLAS_CONST blasint            /* KU */,
    OPENBLAS_CONST double            /* alpha */,
    OPENBLAS_CONST double *            /* A */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST double *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    OPENBLAS_CONST double            /* beta */,
    double *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */
);
static PFNcblas_dgbmv _g_cblas_dgbmv = NULL;
void cblas_dgbmv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            TransA,
    OPENBLAS_CONST blasint            M,
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST blasint            KL,
    OPENBLAS_CONST blasint            KU,
    OPENBLAS_CONST double            alpha,
    OPENBLAS_CONST double *            A,
    OPENBLAS_CONST blasint            lda,
    OPENBLAS_CONST double *            X,
    OPENBLAS_CONST blasint            incX,
    OPENBLAS_CONST double            beta,
    double *            Y,
    OPENBLAS_CONST blasint            incY
)
{
    if(_g_cblas_dgbmv==NULL) {
        _g_cblas_dgbmv = rindow_load_libopenblas_func("cblas_dgbmv"); 
        if(_g_cblas_dgbmv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dgbmv(
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
