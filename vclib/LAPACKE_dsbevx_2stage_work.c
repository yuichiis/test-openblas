#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsbevx_2stage_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsbevx_2stage_work)( /* LAPACKE_dsbevx_2stage_work */
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
    double *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */,
    lapack_int *            /* ifail */
);
static PFNLAPACKE_dsbevx_2stage_work _g_LAPACKE_dsbevx_2stage_work = NULL;
lapack_int LAPACKE_dsbevx_2stage_work(
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
    double *            work,
    lapack_int            lwork,
    lapack_int *            iwork,
    lapack_int *            ifail
)
{
    if(_g_LAPACKE_dsbevx_2stage_work==NULL) {
        _g_LAPACKE_dsbevx_2stage_work = rindow_load_libopenblas_func("LAPACKE_dsbevx_2stage_work"); 
        if(_g_LAPACKE_dsbevx_2stage_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsbevx_2stage_work(
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
        work,
        lwork,
        iwork,
        ifail    
    );
}
