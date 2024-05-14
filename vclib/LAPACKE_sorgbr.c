#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sorgbr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sorgbr)( /* LAPACKE_sorgbr */
    int            /* matrix_layout */,
    char            /* vect */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* tau */
);
static PFNLAPACKE_sorgbr _g_LAPACKE_sorgbr = NULL;
lapack_int LAPACKE_sorgbr(
    int            matrix_layout,
    char            vect,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    float *            a,
    lapack_int            lda,
    const float *            tau
)
{
    if(_g_LAPACKE_sorgbr==NULL) {
        _g_LAPACKE_sorgbr = rindow_load_libopenblas_func("LAPACKE_sorgbr"); 
        if(_g_LAPACKE_sorgbr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sorgbr(
        matrix_layout,
        vect,
        m,
        n,
        k,
        a,
        lda,
        tau    
    );
}
