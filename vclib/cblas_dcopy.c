#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dcopy not found\n";
typedef void (CALLBACK* PFNcblas_dcopy)( /* cblas_dcopy */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST double *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    double *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_dcopy _g_cblas_dcopy = NULL;
void cblas_dcopy(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST double *            x,
    OPENBLAS_CONST blasint            incx,
    double *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_dcopy==NULL) {
        _g_cblas_dcopy = rindow_load_libopenblas_func("cblas_dcopy"); 
        if(_g_cblas_dcopy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dcopy(
        n,
        x,
        incx,
        y,
        incy    
    );
}
