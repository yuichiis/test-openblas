#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dgemv not found\n";
typedef void (CALLBACK* PFNcblas_dgemv)( /* cblas_dgemv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* trans */,
    OPENBLAS_CONST blasint            /* m */,
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST double            /* alpha */,
    OPENBLAS_CONST double *            /* a */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST double *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    OPENBLAS_CONST double            /* beta */,
    double *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_dgemv _g_cblas_dgemv = NULL;
void cblas_dgemv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            trans,
    OPENBLAS_CONST blasint            m,
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST double            alpha,
    OPENBLAS_CONST double *            a,
    OPENBLAS_CONST blasint            lda,
    OPENBLAS_CONST double *            x,
    OPENBLAS_CONST blasint            incx,
    OPENBLAS_CONST double            beta,
    double *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_dgemv==NULL) {
        _g_cblas_dgemv = rindow_load_libopenblas_func("cblas_dgemv"); 
        if(_g_cblas_dgemv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dgemv(
        order,
        trans,
        m,
        n,
        alpha,
        a,
        lda,
        x,
        incx,
        beta,
        y,
        incy    
    );
}
