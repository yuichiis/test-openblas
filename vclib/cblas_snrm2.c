#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_snrm2 not found\n";
typedef float (CALLBACK* PFNcblas_snrm2)( /* cblas_snrm2 */
    OPENBLAS_CONST blasint            /* N */,
    OPENBLAS_CONST float *            /* X */,
    OPENBLAS_CONST blasint            /* incX */
);
static PFNcblas_snrm2 _g_cblas_snrm2 = NULL;
float cblas_snrm2(
    OPENBLAS_CONST blasint            N,
    OPENBLAS_CONST float *            X,
    OPENBLAS_CONST blasint            incX
)
{
    if(_g_cblas_snrm2==NULL) {
        _g_cblas_snrm2 = rindow_load_libopenblas_func("cblas_snrm2"); 
        if(_g_cblas_snrm2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_snrm2(
        N,
        X,
        incX    
    );
}
