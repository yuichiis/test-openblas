#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgemlq not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgemlq)( /* LAPACKE_cgemlq */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_float *            /* t */,
    lapack_int            /* tsize */,
    lapack_complex_float *            /* c */,
    lapack_int            /* ldc */
);
static PFNLAPACKE_cgemlq _g_LAPACKE_cgemlq = NULL;
lapack_int LAPACKE_cgemlq(
    int            matrix_layout,
    char            side,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    const lapack_complex_float *            a,
    lapack_int            lda,
    const lapack_complex_float *            t,
    lapack_int            tsize,
    lapack_complex_float *            c,
    lapack_int            ldc
)
{
    if(_g_LAPACKE_cgemlq==NULL) {
        _g_LAPACKE_cgemlq = rindow_load_libopenblas_func("LAPACKE_cgemlq"); 
        if(_g_LAPACKE_cgemlq==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgemlq(
        matrix_layout,
        side,
        trans,
        m,
        n,
        k,
        a,
        lda,
        t,
        tsize,
        c,
        ldc    
    );
}
