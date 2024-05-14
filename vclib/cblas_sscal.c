#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_sscal not found\n";
typedef void (CALLBACK* PFNcblas_sscal)( /* cblas_sscal */
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST float            /* alpha */,
    float *            /* X */,
    OPENBLAS_CONST blasint            /* incX */
);
static PFNcblas_sscal _g_cblas_sscal = NULL;
void cblas_sscal(
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST float            alpha,
    float *            X,
    OPENBLAS_CONST blasint            incX
)
{
    if(_g_cblas_sscal==NULL) {
        _g_cblas_sscal = rindow_load_libopenblas_func("cblas_sscal"); 
        if(_g_cblas_sscal==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_sscal(
        N,
        alpha,
        X,
        incX    
    );
}
