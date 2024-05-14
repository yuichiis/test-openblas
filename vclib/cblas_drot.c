#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_drot not found\n";
typedef void (CALLBACK* PFNcblas_drot)( /* cblas_drot */
    OPENBLAS_CONST blasint            /* N */,
    double *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    double *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */,
    OPENBLAS_CONST double            /* c */,
    OPENBLAS_CONST double            /* s */
);
static PFNcblas_drot _g_cblas_drot = NULL;
void cblas_drot(
    OPENBLAS_CONST blasint            N,
    double *            X,
    OPENBLAS_CONST blasint            incX,
    double *            Y,
    OPENBLAS_CONST blasint            incY,
    OPENBLAS_CONST double            c,
    OPENBLAS_CONST double            s
)
{
    if(_g_cblas_drot==NULL) {
        _g_cblas_drot = rindow_load_libopenblas_func("cblas_drot"); 
        if(_g_cblas_drot==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_drot(
        N,
        X,
        incX,
        Y,
        incY,
        c,
        s    
    );
}
