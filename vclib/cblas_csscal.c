#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_csscal not found\n";
typedef void (CALLBACK* PFNcblas_csscal)( /* cblas_csscal */
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST float            /* alpha */,
    void *            /* X */,
    OPENBLAS_CONST blasint            /* incX */
);
static PFNcblas_csscal _g_cblas_csscal = NULL;
void cblas_csscal(
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST float            alpha,
    void *            X,
    OPENBLAS_CONST blasint            incX
)
{
    if(_g_cblas_csscal==NULL) {
        _g_cblas_csscal = rindow_load_libopenblas_func("cblas_csscal"); 
        if(_g_cblas_csscal==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_csscal(
        N,
        alpha,
        X,
        incX    
    );
}
