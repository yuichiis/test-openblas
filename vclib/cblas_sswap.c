#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_sswap not found\n";
typedef void (CALLBACK* PFNcblas_sswap)( /* cblas_sswap */
    OPENBLAS_CONST blasint            /* n */,
    float *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    float *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_sswap _g_cblas_sswap = NULL;
void cblas_sswap(
    OPENBLAS_CONST blasint            n,
    float *            x,
    OPENBLAS_CONST blasint            incx,
    float *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_sswap==NULL) {
        _g_cblas_sswap = rindow_load_libopenblas_func("cblas_sswap"); 
        if(_g_cblas_sswap==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_sswap(
        n,
        x,
        incx,
        y,
        incy    
    );
}
