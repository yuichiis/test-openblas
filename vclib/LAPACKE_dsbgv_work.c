#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsbgv_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsbgv_work)( /* LAPACKE_dsbgv_work */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* ka */,
    lapack_int            /* kb */,
    double *            /* ab */,
    lapack_int            /* ldab */,
    double *            /* bb */,
    lapack_int            /* ldbb */,
    double *            /* w */,
    double *            /* z */,
    lapack_int            /* ldz */,
    double *            /* work */
);
static PFNLAPACKE_dsbgv_work _g_LAPACKE_dsbgv_work = NULL;
lapack_int LAPACKE_dsbgv_work(
    int            matrix_layout,
    char            jobz,
    char            uplo,
    lapack_int            n,
    lapack_int            ka,
    lapack_int            kb,
    double *            ab,
    lapack_int            ldab,
    double *            bb,
    lapack_int            ldbb,
    double *            w,
    double *            z,
    lapack_int            ldz,
    double *            work
)
{
    if(_g_LAPACKE_dsbgv_work==NULL) {
        _g_LAPACKE_dsbgv_work = rindow_load_libopenblas_func("LAPACKE_dsbgv_work"); 
        if(_g_LAPACKE_dsbgv_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsbgv_work(
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
        ldz,
        work    
    );
}
