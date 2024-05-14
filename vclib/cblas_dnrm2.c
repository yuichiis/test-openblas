#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dnrm2 not found\n";
typedef double (CALLBACK* PFNcblas_dnrm2)( /* cblas_dnrm2 */
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST double *            /* X */,
    OPENBLAS_CONST blasint            /* incX */
);
static PFNcblas_dnrm2 _g_cblas_dnrm2 = NULL;
double cblas_dnrm2(
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST double *            X,
    OPENBLAS_CONST blasint            incX
)
{
    if(_g_cblas_dnrm2==NULL) {
        _g_cblas_dnrm2 = rindow_load_libopenblas_func("cblas_dnrm2"); 
        if(_g_cblas_dnrm2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_dnrm2(
        N,
        X,
        incX    
    );
}
