#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssbevx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssbevx)( /* LAPACKE_ssbevx */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* range */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    float *            /* ab */,
    lapack_int            /* ldab */,
    float *            /* q */,
    lapack_int            /* ldq */,
    float            /* vl */,
    float            /* vu */,
    lapack_int            /* il */,
    lapack_int            /* iu */,
    float            /* abstol */,
    lapack_int *            /* m */,
    float *            /* w */,
    float *            /* z */,
    lapack_int            /* ldz */,
    lapack_int *            /* ifail */
);
static PFNLAPACKE_ssbevx _g_LAPACKE_ssbevx = NULL;
lapack_int LAPACKE_ssbevx(
    int            matrix_layout,
    char            jobz,
    char            range,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    float *            ab,
    lapack_int            ldab,
    float *            q,
    lapack_int            ldq,
    float            vl,
    float            vu,
    lapack_int            il,
    lapack_int            iu,
    float            abstol,
    lapack_int *            m,
    float *            w,
    float *            z,
    lapack_int            ldz,
    lapack_int *            ifail
)
{
    if(_g_LAPACKE_ssbevx==NULL) {
        _g_LAPACKE_ssbevx = rindow_load_libopenblas_func("LAPACKE_ssbevx"); 
        if(_g_LAPACKE_ssbevx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssbevx(
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
