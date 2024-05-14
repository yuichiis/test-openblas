#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_scopy not found\n";
typedef void (CALLBACK* PFNcblas_scopy)( /* cblas_scopy */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST float *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    float *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_scopy _g_cblas_scopy = NULL;
void cblas_scopy(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST float *            x,
    OPENBLAS_CONST blasint            incx,
    float *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_scopy==NULL) {
        _g_cblas_scopy = rindow_load_libopenblas_func("cblas_scopy"); 
        if(_g_cblas_scopy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_scopy(
        n,
        x,
        incx,
        y,
        incy    
    );
}
