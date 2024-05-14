#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_cdotc_sub not found\n";
typedef void (CALLBACK* PFNcblas_cdotc_sub)( /* cblas_cdotc_sub */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */,
    OPENBLAS_CONST void *            /* y */,
    OPENBLAS_CONST blasint            /* incy */,
    void *            /* ret */
);
static PFNcblas_cdotc_sub _g_cblas_cdotc_sub = NULL;
void cblas_cdotc_sub(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx,
    OPENBLAS_CONST void *            y,
    OPENBLAS_CONST blasint            incy,
    void *            ret
)
{
    if(_g_cblas_cdotc_sub==NULL) {
        _g_cblas_cdotc_sub = rindow_load_libopenblas_func("cblas_cdotc_sub"); 
        if(_g_cblas_cdotc_sub==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_cdotc_sub(
        n,
        x,
        incx,
        y,
        incy,
        ret    
    );
}
