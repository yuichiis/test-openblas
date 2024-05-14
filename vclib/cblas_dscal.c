#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dscal not found\n";
typedef void (CALLBACK* PFNcblas_dscal)( /* cblas_dscal */
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST double            /* alpha */,
    double *            /* X */,
    OPENBLAS_CONST blasint            /* incX */
);
static PFNcblas_dscal _g_cblas_dscal = NULL;
void cblas_dscal(
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST double            alpha,
    double *            X,
    OPENBLAS_CONST blasint            incX
)
{
    if(_g_cblas_dscal==NULL) {
        _g_cblas_dscal = rindow_load_libopenblas_func("cblas_dscal"); 
        if(_g_cblas_dscal==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_dscal(
        N,
        alpha,
        X,
        incX    
    );
}
