#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_sgemv not found\n";
typedef void (CALLBACK* PFNcblas_sgemv)( /* cblas_sgemv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* trans */,
    OPENBLAS_CONST blasint            /* m */,
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST float            /* alpha */,
    OPENBLAS_CONST float *            /* a */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST float *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    OPENBLAS_CONST float            /* beta */,
    float *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_sgemv _g_cblas_sgemv = NULL;
void cblas_sgemv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            trans,
    OPENBLAS_CONST blasint            m,
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST float            alpha,
    OPENBLAS_CONST float *            a,
    OPENBLAS_CONST blasint            lda,
    OPENBLAS_CONST float *            x,
    OPENBLAS_CONST blasint            incx,
    OPENBLAS_CONST float            beta,
    float *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_sgemv==NULL) {
        _g_cblas_sgemv = rindow_load_libopenblas_func("cblas_sgemv"); 
        if(_g_cblas_sgemv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_sgemv(
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
