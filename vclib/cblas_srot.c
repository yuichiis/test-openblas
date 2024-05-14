#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_srot not found\n";
typedef void (CALLBACK* PFNcblas_srot)( /* cblas_srot */
    OPENBLAS_CONST blasint            /* N */,
    float *            /* X */,
    OPENBLAS_CONST blasint            /* incX */,
    float *            /* Y */,
    OPENBLAS_CONST blasint            /* incY */,
    OPENBLAS_CONST float            /* c */,
    OPENBLAS_CONST float            /* s */
);
static PFNcblas_srot _g_cblas_srot = NULL;
void cblas_srot(
    OPENBLAS_CONST blasint            N,
    float *            X,
    OPENBLAS_CONST blasint            incX,
    float *            Y,
    OPENBLAS_CONST blasint            incY,
    OPENBLAS_CONST float            c,
    OPENBLAS_CONST float            s
)
{
    if(_g_cblas_srot==NULL) {
        _g_cblas_srot = rindow_load_libopenblas_func("cblas_srot"); 
        if(_g_cblas_srot==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_srot(
        N,
        X,
        incX,
        Y,
        incY,
        c,
        s    
    );
}
