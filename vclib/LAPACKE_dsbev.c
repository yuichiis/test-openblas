#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsbev not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsbev)( /* LAPACKE_dsbev */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    double *            /* ab */,
    lapack_int            /* ldab */,
    double *            /* w */,
    double *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_dsbev _g_LAPACKE_dsbev = NULL;
lapack_int LAPACKE_dsbev(
    int            matrix_layout,
    char            jobz,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    double *            ab,
    lapack_int            ldab,
    double *            w,
    double *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_dsbev==NULL) {
        _g_LAPACKE_dsbev = rindow_load_libopenblas_func("LAPACKE_dsbev"); 
        if(_g_LAPACKE_dsbev==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsbev(
        matrix_layout,
        jobz,
        uplo,
        n,
        kd,
        ab,
        ldab,
        w,
        z,
        ldz    
    );
}
