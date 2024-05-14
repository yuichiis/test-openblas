#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_ismax not found\n";
typedef CBLAS_INDEX (CALLBACK* PFNcblas_ismax)( /* cblas_ismax */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST float *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_ismax _g_cblas_ismax = NULL;
CBLAS_INDEX cblas_ismax(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST float *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_ismax==NULL) {
        _g_cblas_ismax = rindow_load_libopenblas_func("cblas_ismax"); 
        if(_g_cblas_ismax==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_ismax(
        n,
        x,
        incx    
    );
}
