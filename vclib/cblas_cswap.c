#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_cswap not found\n";
typedef void (CALLBACK* PFNcblas_cswap)( /* cblas_cswap */
    OPENBLAS_CONST blasint            /* n */,
    void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    void *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_cswap _g_cblas_cswap = NULL;
void cblas_cswap(
    OPENBLAS_CONST blasint            n,
    void *            x,
    OPENBLAS_CONST blasint            incx,
    void *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_cswap==NULL) {
        _g_cblas_cswap = rindow_load_libopenblas_func("cblas_cswap"); 
        if(_g_cblas_cswap==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_cswap(
        n,
        x,
        incx,
        y,
        incy    
    );
}
