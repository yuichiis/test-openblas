#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chbevx_2stage not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chbevx_2stage)( /* LAPACKE_chbevx_2stage */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* range */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    lapack_complex_float *            /* ab */,
    lapack_int            /* ldab */,
    lapack_complex_float *            /* q */,
    lapack_int            /* ldq */,
    float            /* vl */,
    float            /* vu */,
    lapack_int            /* il */,
    lapack_int            /* iu */,
    float            /* abstol */,
    lapack_int *            /* m */,
    float *            /* w */,
    lapack_complex_float *            /* z */,
    lapack_int            /* ldz */,
    lapack_int *            /* ifail */
);
static PFNLAPACKE_chbevx_2stage _g_LAPACKE_chbevx_2stage = NULL;
lapack_int LAPACKE_chbevx_2stage(
    int            matrix_layout,
    char            jobz,
    char            range,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    lapack_complex_float *            ab,
    lapack_int            ldab,
    lapack_complex_float *            q,
    lapack_int            ldq,
    float            vl,
    float            vu,
    lapack_int            il,
    lapack_int            iu,
    float            abstol,
    lapack_int *            m,
    float *            w,
    lapack_complex_float *            z,
    lapack_int            ldz,
    lapack_int *            ifail
)
{
    if(_g_LAPACKE_chbevx_2stage==NULL) {
        _g_LAPACKE_chbevx_2stage = rindow_load_libopenblas_func("LAPACKE_chbevx_2stage"); 
        if(_g_LAPACKE_chbevx_2stage==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chbevx_2stage(
        matrix_layout,
        jobz,
        range,
        uplo,
        n,
        kd,
        ab,
        ldab,
        q,
        ldq,
        vl,
        vu,
        il,
        iu,
        abstol,
        m,
        w,
        z,
        ldz,
        ifail    
    );
}
