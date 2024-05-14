#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgelq not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgelq)( /* LAPACKE_sgelq */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* t */,
    lapack_int            /* tsize */
);
static PFNLAPACKE_sgelq _g_LAPACKE_sgelq = NULL;
lapack_int LAPACKE_sgelq(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            t,
    lapack_int            tsize
)
{
    if(_g_LAPACKE_sgelq==NULL) {
        _g_LAPACKE_sgelq = rindow_load_libopenblas_func("LAPACKE_sgelq"); 
        if(_g_LAPACKE_sgelq==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgelq(
        matrix_layout,
        m,
        n,
        a,
        lda,
        t,
        tsize    
    );
}
