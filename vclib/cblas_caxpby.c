#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_caxpby not found\n";
typedef void (CALLBACK* PFNcblas_caxpby)( /* cblas_caxpby */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* alpha */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    OPENBLAS_CONST void *            /* beta */,
    void *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_caxpby _g_cblas_caxpby = NULL;
void cblas_caxpby(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            alpha,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx,
    OPENBLAS_CONST void *            beta,
    void *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_caxpby==NULL) {
        _g_cblas_caxpby = rindow_load_libopenblas_func("cblas_caxpby"); 
        if(_g_cblas_caxpby==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_caxpby(
        n,
        alpha,
        x,
        incx,
        beta,
        y,
        incy    
    );
}
