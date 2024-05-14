#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zpbcon_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zpbcon_work)( /* LAPACKE_zpbcon_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    const lapack_complex_double *            /* ab */,
    lapack_int            /* ldab */,
    double            /* anorm */,
    double *            /* rcond */,
    lapack_complex_double *            /* work */,
    double *            /* rwork */
);
static PFNLAPACKE_zpbcon_work _g_LAPACKE_zpbcon_work = NULL;
lapack_int LAPACKE_zpbcon_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    const lapack_complex_double *            ab,
    lapack_int            ldab,
    double            anorm,
    double *            rcond,
    lapack_complex_double *            work,
    double *            rwork
)
{
    if(_g_LAPACKE_zpbcon_work==NULL) {
        _g_LAPACKE_zpbcon_work = rindow_load_libopenblas_func("LAPACKE_zpbcon_work"); 
        if(_g_LAPACKE_zpbcon_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zpbcon_work(
        matrix_layout,
        uplo,
        n,
        kd,
        ab,
        ldab,
        anorm,
        rcond,
        work,
        rwork    
    );
}
