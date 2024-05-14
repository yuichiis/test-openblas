#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_caxpyc not found\n";
typedef void (CALLBACK* PFNcblas_caxpyc)( /* cblas_caxpyc */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* alpha */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    void *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_caxpyc _g_cblas_caxpyc = NULL;
void cblas_caxpyc(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            alpha,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx,
    void *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_caxpyc==NULL) {
        _g_cblas_caxpyc = rindow_load_libopenblas_func("cblas_caxpyc"); 
        if(_g_cblas_caxpyc==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_caxpyc(
        n,
        alpha,
        x,
        incx,
        y,
        incy    
    );
}
