#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_icamin not found\n";
typedef CBLAS_INDEX (CALLBACK* PFNcblas_icamin)( /* cblas_icamin */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_icamin _g_cblas_icamin = NULL;
CBLAS_INDEX cblas_icamin(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_icamin==NULL) {
        _g_cblas_icamin = rindow_load_libopenblas_func("cblas_icamin"); 
        if(_g_cblas_icamin==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_icamin(
        n,
        x,
        incx    
    );
}
