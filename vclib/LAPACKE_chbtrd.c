#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chbtrd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chbtrd)( /* LAPACKE_chbtrd */
    int            /* matrix_layout */,
    char            /* vect */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    lapack_complex_float *            /* ab */,
    lapack_int            /* ldab */,
    float *            /* d */,
    float *            /* e */,
    lapack_complex_float *            /* q */,
    lapack_int            /* ldq */
);
static PFNLAPACKE_chbtrd _g_LAPACKE_chbtrd = NULL;
lapack_int LAPACKE_chbtrd(
    int            matrix_layout,
    char            vect,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    lapack_complex_float *            ab,
    lapack_int            ldab,
    float *            d,
    float *            e,
    lapack_complex_float *            q,
    lapack_int            ldq
)
{
    if(_g_LAPACKE_chbtrd==NULL) {
        _g_LAPACKE_chbtrd = rindow_load_libopenblas_func("LAPACKE_chbtrd"); 
        if(_g_LAPACKE_chbtrd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chbtrd(
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
