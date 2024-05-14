#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clange not found\n";
typedef float (CALLBACK* PFNLAPACKE_clange)( /* LAPACKE_clange */
    int            /* matrix_layout */,
    char            /* norm */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_clange _g_LAPACKE_clange = NULL;
float LAPACKE_clange(
    int            matrix_layout,
    char            norm,
    lapack_int            m,
    lapack_int            n,
    const lapack_complex_float *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_clange==NULL) {
        _g_LAPACKE_clange = rindow_load_libopenblas_func("LAPACKE_clange"); 
        if(_g_LAPACKE_clange==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clange(
        matrix_layout,
        norm,
        m,
        n,
        a,
        lda    
    );
}
