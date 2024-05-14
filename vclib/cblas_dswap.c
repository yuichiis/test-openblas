#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dswap not found\n";
typedef void (CALLBACK* PFNcblas_dswap)( /* cblas_dswap */
    OPENBLAS_CONST blasint            /* n */,
    double *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    double *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_dswap _g_cblas_dswap = NULL;
void cblas_dswap(
    OPENBLAS_CONST blasint            n,
    double *            x,
    OPENBLAS_CONST blasint            incx,
    double *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_dswap==NULL) {
        _g_cblas_dswap = rindow_load_libopenblas_func("cblas_dswap"); 
        if(_g_cblas_dswap==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dswap(
        n,
        x,
        incx,
        y,
        incy    
    );
}
