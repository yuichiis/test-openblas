#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_izmax not found\n";
typedef CBLAS_INDEX (CALLBACK* PFNcblas_izmax)( /* cblas_izmax */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_izmax _g_cblas_izmax = NULL;
CBLAS_INDEX cblas_izmax(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_izmax==NULL) {
        _g_cblas_izmax = rindow_load_libopenblas_func("cblas_izmax"); 
        if(_g_cblas_izmax==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_izmax(
        n,
        x,
        incx    
    );
}
