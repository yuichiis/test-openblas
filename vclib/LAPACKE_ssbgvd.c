#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssbgvd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssbgvd)( /* LAPACKE_ssbgvd */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* ka */,
    lapack_int            /* kb */,
    float *            /* ab */,
    lapack_int            /* ldab */,
    float *            /* bb */,
    lapack_int            /* ldbb */,
    float *            /* w */,
    float *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_ssbgvd _g_LAPACKE_ssbgvd = NULL;
lapack_int LAPACKE_ssbgvd(
    int            matrix_layout,
    char            jobz,
    char            uplo,
    lapack_int            n,
    lapack_int            ka,
    lapack_int            kb,
    float *            ab,
    lapack_int            ldab,
    float *            bb,
    lapack_int            ldbb,
    float *            w,
    float *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_ssbgvd==NULL) {
        _g_LAPACKE_ssbgvd = rindow_load_libopenblas_func("LAPACKE_ssbgvd"); 
        if(_g_LAPACKE_ssbgvd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssbgvd(
        matrix_layout,
        jobz,
        uplo,
        n,
        ka,
        kb,
        ab,
        ldab,
        bb,
        ldbb,
        w,
        z,
        ldz    
    );
}
