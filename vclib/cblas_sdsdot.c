#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_sdsdot not found\n";
typedef float (CALLBACK* PFNcblas_sdsdot)( /* cblas_sdsdot */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST float            /* alpha */,
    OPENBLAS_CONST float *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    OPENBLAS_CONST float *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_sdsdot _g_cblas_sdsdot = NULL;
float cblas_sdsdot(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST float            alpha,
    OPENBLAS_CONST float *            x,
    OPENBLAS_CONST blasint            incx,
    OPENBLAS_CONST float *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_sdsdot==NULL) {
        _g_cblas_sdsdot = rindow_load_libopenblas_func("cblas_sdsdot"); 
        if(_g_cblas_sdsdot==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_sdsdot(
        n,
        alpha,
        x,
        incx,
        y,
        incy    
    );
}
