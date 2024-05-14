#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_dzasum not found\n";
typedef double (CALLBACK* PFNcblas_dzasum)( /* cblas_dzasum */
    OPENBLAS_CONST blasint            /* n */,
    OPENBLAS_CONST void *            /* x */,
    OPENBLAS_CONST blasint            /* incx */
);
static PFNcblas_dzasum _g_cblas_dzasum = NULL;
double cblas_dzasum(
    OPENBLAS_CONST blasint            n,
    OPENBLAS_CONST void *            x,
    OPENBLAS_CONST blasint            incx
)
{
    if(_g_cblas_dzasum==NULL) {
        _g_cblas_dzasum = rindow_load_libopenblas_func("cblas_dzasum"); 
        if(_g_cblas_dzasum==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_cblas_dzasum(
        n,
        x,
        incx    
    );
}
