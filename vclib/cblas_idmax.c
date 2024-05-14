#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_idmax not found\n";
typedef CBLAS_INDEX (CALLBACK* PFNcblas_idmax)( /* cblas_idmax */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST double *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_idmax _g_cblas_idmax = NULL;
CBLAS_INDEX cblas_idmax(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST double *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_idmax==NULL) {
        _g_cblas_idmax = rindow_load_libopenblas_func("cblas_idmax"); 
        if(_g_cblas_idmax==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_idmax(
        n,
        x,
        incx    
    );
}
