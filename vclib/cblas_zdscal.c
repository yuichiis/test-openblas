#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_zdscal not found\n";
typedef void (CALLBACK* PFNcblas_zdscal)( /* cblas_zdscal */
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST double            /* alpha */,
    void *            /* X */,
    OPENBLAS_CONST blasint            /* incX */
);
static PFNcblas_zdscal _g_cblas_zdscal = NULL;
void cblas_zdscal(
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST double            alpha,
    void *            X,
    OPENBLAS_CONST blasint            incX
)
{
    if(_g_cblas_zdscal==NULL) {
        _g_cblas_zdscal = rindow_load_libopenblas_func("cblas_zdscal"); 
        if(_g_cblas_zdscal==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_zdscal(
        N,
        alpha,
        X,
        incX    
    );
}
