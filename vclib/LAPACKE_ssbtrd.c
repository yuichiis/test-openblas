#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssbtrd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssbtrd)( /* LAPACKE_ssbtrd */
    int            /* matrix_layout */,
    char            /* vect */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    float *            /* ab */,
    lapack_int            /* ldab */,
    float *            /* d */,
    float *            /* e */,
    float *            /* q */,
    lapack_int            /* ldq */
);
static PFNLAPACKE_ssbtrd _g_LAPACKE_ssbtrd = NULL;
lapack_int LAPACKE_ssbtrd(
    int            matrix_layout,
    char            vect,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    float *            ab,
    lapack_int            ldab,
    float *            d,
    float *            e,
    float *            q,
    lapack_int            ldq
)
{
    if(_g_LAPACKE_ssbtrd==NULL) {
        _g_LAPACKE_ssbtrd = rindow_load_libopenblas_func("LAPACKE_ssbtrd"); 
        if(_g_LAPACKE_ssbtrd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssbtrd(
        matrix_layout,
        vect,
        uplo,
        n,
        kd,
        ab,
        ldab,
        d,
        e,
        q,
        ldq    
    );
}
