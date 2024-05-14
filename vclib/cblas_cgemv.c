#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_cgemv not found\n";
typedef void (CALLBACK* PFNcblas_cgemv)( /* cblas_cgemv */
    OPENBLAS_CONST enum CBLAS_ORDER            /* order */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* trans */,
    OPENBLAS_CONST blasint            /* m */,
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* alpha */,
    OPENBLAS_CONST void *            /* a */,
    OPENBLAS_CONST blasint            /* lda */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    OPENBLAS_CONST void *            /* beta */,
    void *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_cgemv _g_cblas_cgemv = NULL;
void cblas_cgemv(
    OPENBLAS_CONST enum CBLAS_ORDER            order,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            trans,
    OPENBLAS_CONST blasint            m,
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            alpha,
    OPENBLAS_CONST void *            a,
    OPENBLAS_CONST blasint            lda,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx,
    OPENBLAS_CONST void *            beta,
    void *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_cgemv==NULL) {
        _g_cblas_cgemv = rindow_load_libopenblas_func("cblas_cgemv"); 
        if(_g_cblas_cgemv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_cgemv(
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
