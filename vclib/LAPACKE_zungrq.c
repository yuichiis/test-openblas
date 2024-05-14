#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zungrq not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zungrq)( /* LAPACKE_zungrq */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_double *            /* tau */
);
static PFNLAPACKE_zungrq _g_LAPACKE_zungrq = NULL;
lapack_int LAPACKE_zungrq(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_complex_double *            tau
)
{
    if(_g_LAPACKE_zungrq==NULL) {
        _g_LAPACKE_zungrq = rindow_load_libopenblas_func("LAPACKE_zungrq"); 
        if(_g_LAPACKE_zungrq==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zungrq(
        matrix_layout,
        m,
        n,
        k,
        a,
        lda,
        tau    
    );
}
