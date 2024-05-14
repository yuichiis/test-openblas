#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlange not found\n";
typedef double (CALLBACK* PFNLAPACKE_dlange)( /* LAPACKE_dlange */
    int            /* matrix_layout */,
    char            /* norm */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const double *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_dlange _g_LAPACKE_dlange = NULL;
double LAPACKE_dlange(
    int            matrix_layout,
    char            norm,
    lapack_int            m,
    lapack_int            n,
    const double *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_dlange==NULL) {
        _g_LAPACKE_dlange = rindow_load_libopenblas_func("LAPACKE_dlange"); 
        if(_g_LAPACKE_dlange==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlange(
        matrix_layout,
        norm,
        m,
        n,
        a,
        lda    
    );
}
