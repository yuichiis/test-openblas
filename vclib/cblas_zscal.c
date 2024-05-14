#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_zscal not found\n";
typedef void (CALLBACK* PFNcblas_zscal)( /* cblas_zscal */
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST void *            /* alpha */,
    void *            /* X */,
    OPENBLAS_CONST blasint            /* incX */
);
static PFNcblas_zscal _g_cblas_zscal = NULL;
void cblas_zscal(
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST void *            alpha,
    void *            X,
    OPENBLAS_CONST blasint            incX
)
{
    if(_g_cblas_zscal==NULL) {
        _g_cblas_zscal = rindow_load_libopenblas_func("cblas_zscal"); 
        if(_g_cblas_zscal==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_zscal(
        N,
        alpha,
        X,
        incX    
    );
}
