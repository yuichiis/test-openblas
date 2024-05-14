#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_ccopy not found\n";
typedef void (CALLBACK* PFNcblas_ccopy)( /* cblas_ccopy */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    void *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_ccopy _g_cblas_ccopy = NULL;
void cblas_ccopy(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx,
    void *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_ccopy==NULL) {
        _g_cblas_ccopy = rindow_load_libopenblas_func("cblas_ccopy"); 
        if(_g_cblas_ccopy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_ccopy(
        n,
        x,
        incx,
        y,
        incy    
    );
}
