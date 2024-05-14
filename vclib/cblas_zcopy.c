#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_zcopy not found\n";
typedef void (CALLBACK* PFNcblas_zcopy)( /* cblas_zcopy */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    void *            /* y */,
    OPENBLAS_CONST blasint            /* incy */
);
static PFNcblas_zcopy _g_cblas_zcopy = NULL;
void cblas_zcopy(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx,
    void *            y,
    OPENBLAS_CONST blasint            incy
)
{
    if(_g_cblas_zcopy==NULL) {
        _g_cblas_zcopy = rindow_load_libopenblas_func("cblas_zcopy"); 
        if(_g_cblas_zcopy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_zcopy(
        n,
        x,
        incx,
        y,
        incy    
    );
}
