#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhbgv_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhbgv_work)( /* LAPACKE_zhbgv_work */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* ka */,
    lapack_int            /* kb */,
    lapack_complex_double *            /* ab */,
    lapack_int            /* ldab */,
    lapack_complex_double *            /* bb */,
    lapack_int            /* ldbb */,
    double *            /* w */,
    lapack_complex_double *            /* z */,
    lapack_int            /* ldz */,
    lapack_complex_double *            /* work */,
    double *            /* rwork */
);
static PFNLAPACKE_zhbgv_work _g_LAPACKE_zhbgv_work = NULL;
lapack_int LAPACKE_zhbgv_work(
    int            matrix_layout,
    char            jobz,
    char            uplo,
    lapack_int            n,
    lapack_int            ka,
    lapack_int            kb,
    lapack_complex_double *            ab,
    lapack_int            ldab,
    lapack_complex_double *            bb,
    lapack_int            ldbb,
    double *            w,
    lapack_complex_double *            z,
    lapack_int            ldz,
    lapack_complex_double *            work,
    double *            rwork
)
{
    if(_g_LAPACKE_zhbgv_work==NULL) {
        _g_LAPACKE_zhbgv_work = rindow_load_libopenblas_func("LAPACKE_zhbgv_work"); 
        if(_g_LAPACKE_zhbgv_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhbgv_work(
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
        work,
        rwork    
    );
}
