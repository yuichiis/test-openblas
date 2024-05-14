#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_cscal not found\n";
typedef void (CALLBACK* PFNcblas_cscal)( /* cblas_cscal */
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST void *            /* alpha */,
    void *            /* X */,
    OPENBLAS_CONST blasint            /* incX */
);
static PFNcblas_cscal _g_cblas_cscal = NULL;
void cblas_cscal(
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST void *            alpha,
    void *            X,
    OPENBLAS_CONST blasint            incX
)
{
    if(_g_cblas_cscal==NULL) {
        _g_cblas_cscal = rindow_load_libopenblas_func("cblas_cscal"); 
        if(_g_cblas_cscal==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_cscal(
        N,
        alpha,
        X,
        incX    
    );
}
