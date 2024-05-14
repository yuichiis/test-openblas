#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chbev_2stage not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chbev_2stage)( /* LAPACKE_chbev_2stage */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    lapack_complex_float *            /* ab */,
    lapack_int            /* ldab */,
    float *            /* w */,
    lapack_complex_float *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_chbev_2stage _g_LAPACKE_chbev_2stage = NULL;
lapack_int LAPACKE_chbev_2stage(
    int            matrix_layout,
    char            jobz,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    lapack_complex_float *            ab,
    lapack_int            ldab,
    float *            w,
    lapack_complex_float *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_chbev_2stage==NULL) {
        _g_LAPACKE_chbev_2stage = rindow_load_libopenblas_func("LAPACKE_chbev_2stage"); 
        if(_g_LAPACKE_chbev_2stage==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chbev_2stage(
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
