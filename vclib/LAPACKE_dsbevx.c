#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsbevx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsbevx)( /* LAPACKE_dsbevx */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* range */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    double *            /* ab */,
    lapack_int            /* ldab */,
    double *            /* q */,
    lapack_int            /* ldq */,
    double            /* vl */,
    double            /* vu */,
    lapack_int            /* il */,
    lapack_int            /* iu */,
    double            /* abstol */,
    lapack_int *            /* m */,
    double *            /* w */,
    double *            /* z */,
    lapack_int            /* ldz */,
    lapack_int *            /* ifail */
);
static PFNLAPACKE_dsbevx _g_LAPACKE_dsbevx = NULL;
lapack_int LAPACKE_dsbevx(
    int            matrix_layout,
    char            jobz,
    char            range,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    double *            ab,
    lapack_int            ldab,
    double *            q,
    lapack_int            ldq,
    double            vl,
    double            vu,
    lapack_int            il,
    lapack_int            iu,
    double            abstol,
    lapack_int *            m,
    double *            w,
    double *            z,
    lapack_int            ldz,
    lapack_int *            ifail
)
{
    if(_g_LAPACKE_dsbevx==NULL) {
        _g_LAPACKE_dsbevx = rindow_load_libopenblas_func("LAPACKE_dsbevx"); 
        if(_g_LAPACKE_dsbevx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsbevx(
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
