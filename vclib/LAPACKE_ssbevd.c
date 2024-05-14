#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssbevd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssbevd)( /* LAPACKE_ssbevd */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    float *            /* ab */,
    lapack_int            /* ldab */,
    float *            /* w */,
    float *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_ssbevd _g_LAPACKE_ssbevd = NULL;
lapack_int LAPACKE_ssbevd(
    int            matrix_layout,
    char            jobz,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    float *            ab,
    lapack_int            ldab,
    float *            w,
    float *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_ssbevd==NULL) {
        _g_LAPACKE_ssbevd = rindow_load_libopenblas_func("LAPACKE_ssbevd"); 
        if(_g_LAPACKE_ssbevd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssbevd(
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
