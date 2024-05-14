#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dzsum not found\n";
typedef double (CALLBACK* PFNcblas_dzsum)( /* cblas_dzsum */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_dzsum _g_cblas_dzsum = NULL;
double cblas_dzsum(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_dzsum==NULL) {
        _g_cblas_dzsum = rindow_load_libopenblas_func("cblas_dzsum"); 
        if(_g_cblas_dzsum==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_dzsum(
        n,
        x,
        incx    
    );
}
