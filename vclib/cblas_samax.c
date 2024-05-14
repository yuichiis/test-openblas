#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_samax not found\n";
typedef float (CALLBACK* PFNcblas_samax)( /* cblas_samax */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST float *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_samax _g_cblas_samax = NULL;
float cblas_samax(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST float *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_samax==NULL) {
        _g_cblas_samax = rindow_load_libopenblas_func("cblas_samax"); 
        if(_g_cblas_samax==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_samax(
        n,
        x,
        incx    
    );
}
