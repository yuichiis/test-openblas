#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_izamin not found\n";
typedef CBLAS_INDEX (CALLBACK* PFNcblas_izamin)( /* cblas_izamin */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_izamin _g_cblas_izamin = NULL;
CBLAS_INDEX cblas_izamin(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_izamin==NULL) {
        _g_cblas_izamin = rindow_load_libopenblas_func("cblas_izamin"); 
        if(_g_cblas_izamin==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_izamin(
        n,
        x,
        incx    
    );
}
