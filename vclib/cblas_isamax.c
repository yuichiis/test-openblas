#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_isamax not found\n";
typedef CBLAS_INDEX (CALLBACK* PFNcblas_isamax)( /* cblas_isamax */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST float *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_isamax _g_cblas_isamax = NULL;
CBLAS_INDEX cblas_isamax(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST float *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_isamax==NULL) {
        _g_cblas_isamax = rindow_load_libopenblas_func("cblas_isamax"); 
        if(_g_cblas_isamax==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_isamax(
        n,
        x,
        incx    
    );
}
