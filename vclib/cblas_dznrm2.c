#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dznrm2 not found\n";
typedef double (CALLBACK* PFNcblas_dznrm2)( /* cblas_dznrm2 */
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST void *            /* X */,
    OPENBLAS_CONST blasint            /* incX */
);
static PFNcblas_dznrm2 _g_cblas_dznrm2 = NULL;
double cblas_dznrm2(
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST void *            X,
    OPENBLAS_CONST blasint            incX
)
{
    if(_g_cblas_dznrm2==NULL) {
        _g_cblas_dznrm2 = rindow_load_libopenblas_func("cblas_dznrm2"); 
        if(_g_cblas_dznrm2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_dznrm2(
        N,
        X,
        incX    
    );
}
