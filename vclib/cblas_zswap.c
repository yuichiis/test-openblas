#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_zswap not found\n";
typedef void (CALLBACK* PFNcblas_zswap)( /* cblas_zswap */
    OPENBLAS_CONST blasint            /* n */,
    void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    void *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_zswap _g_cblas_zswap = NULL;
void cblas_zswap(
    OPENBLAS_CONST blasint            n,
    void *            x,
    OPENBLAS_CONST blasint            incx,
    void *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_zswap==NULL) {
        _g_cblas_zswap = rindow_load_libopenblas_func("cblas_zswap"); 
        if(_g_cblas_zswap==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_zswap(
        n,
        x,
        incx,
        y,
        incy    
    );
}
