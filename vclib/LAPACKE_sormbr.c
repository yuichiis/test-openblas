#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sormbr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sormbr)( /* LAPACKE_sormbr */
    int            /* matrix_layout */,
    char            /* vect */,
    char            /* side */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* tau */,
    float *            /* c */,
    lapack_int            /* ldc */
);
static PFNLAPACKE_sormbr _g_LAPACKE_sormbr = NULL;
lapack_int LAPACKE_sormbr(
    int            matrix_layout,
    char            vect,
    char            side,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    const float *            a,
    lapack_int            lda,
    const float *            tau,
    float *            c,
    lapack_int            ldc
)
{
    if(_g_LAPACKE_sormbr==NULL) {
        _g_LAPACKE_sormbr = rindow_load_libopenblas_func("LAPACKE_sormbr"); 
        if(_g_LAPACKE_sormbr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sormbr(
        matrix_layout,
        vect,
        side,
        trans,
        m,
        n,
        k,
        a,
        lda,
        tau,
        c,
        ldc    
    );
}
