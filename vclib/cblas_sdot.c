#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_sdot not found\n";
typedef float (CALLBACK* PFNcblas_sdot)( /* cblas_sdot */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST float *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    OPENBLAS_CONST float *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_sdot _g_cblas_sdot = NULL;
float cblas_sdot(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST float *            x,
    OPENBLAS_CONST blasint            incx,
    OPENBLAS_CONST float *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_sdot==NULL) {
        _g_cblas_sdot = rindow_load_libopenblas_func("cblas_sdot"); 
        if(_g_cblas_sdot==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_sdot(
        n,
        x,
        incx,
        y,
        incy    
    );
}
