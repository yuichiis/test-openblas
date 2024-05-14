#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsbgvx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsbgvx)( /* LAPACKE_dsbgvx */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* range */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* ka */,
    lapack_int            /* kb */,
    double *            /* ab */,
    lapack_int            /* ldab */,
    double *            /* bb */,
    lapack_int            /* ldbb */,
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
static PFNLAPACKE_dsbgvx _g_LAPACKE_dsbgvx = NULL;
lapack_int LAPACKE_dsbgvx(
    int            matrix_layout,
    char            jobz,
    char            range,
    char            uplo,
    lapack_int            n,
    lapack_int            ka,
    lapack_int            kb,
    double *            ab,
    lapack_int            ldab,
    double *            bb,
    lapack_int            ldbb,
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
    if(_g_LAPACKE_dsbgvx==NULL) {
        _g_LAPACKE_dsbgvx = rindow_load_libopenblas_func("LAPACKE_dsbgvx"); 
        if(_g_LAPACKE_dsbgvx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsbgvx(
        matrix_layout,
        jobz,
        range,
        uplo,
        n,
        ka,
        kb,
        ab,
        ldab,
        bb,
        ldbb,
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
