#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsbtrd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsbtrd)( /* LAPACKE_dsbtrd */
    int            /* matrix_layout */,
    char            /* vect */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    double *            /* ab */,
    lapack_int            /* ldab */,
    double *            /* d */,
    double *            /* e */,
    double *            /* q */,
    lapack_int            /* ldq */
);
static PFNLAPACKE_dsbtrd _g_LAPACKE_dsbtrd = NULL;
lapack_int LAPACKE_dsbtrd(
    int            matrix_layout,
    char            vect,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    double *            ab,
    lapack_int            ldab,
    double *            d,
    double *            e,
    double *            q,
    lapack_int            ldq
)
{
    if(_g_LAPACKE_dsbtrd==NULL) {
        _g_LAPACKE_dsbtrd = rindow_load_libopenblas_func("LAPACKE_dsbtrd"); 
        if(_g_LAPACKE_dsbtrd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsbtrd(
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
