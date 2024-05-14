#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chbgvd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chbgvd)( /* LAPACKE_chbgvd */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* ka */,
    lapack_int            /* kb */,
    lapack_complex_float *            /* ab */,
    lapack_int            /* ldab */,
    lapack_complex_float *            /* bb */,
    lapack_int            /* ldbb */,
    float *            /* w */,
    lapack_complex_float *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_chbgvd _g_LAPACKE_chbgvd = NULL;
lapack_int LAPACKE_chbgvd(
    int            matrix_layout,
    char            jobz,
    char            uplo,
    lapack_int            n,
    lapack_int            ka,
    lapack_int            kb,
    lapack_complex_float *            ab,
    lapack_int            ldab,
    lapack_complex_float *            bb,
    lapack_int            ldbb,
    float *            w,
    lapack_complex_float *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_chbgvd==NULL) {
        _g_LAPACKE_chbgvd = rindow_load_libopenblas_func("LAPACKE_chbgvd"); 
        if(_g_LAPACKE_chbgvd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chbgvd(
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
