#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctbcon_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctbcon_work)( /* LAPACKE_ctbcon_work */
    int            /* matrix_layout */,
    char            /* norm */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    const lapack_complex_float *            /* ab */,
    lapack_int            /* ldab */,
    float *            /* rcond */,
    lapack_complex_float *            /* work */,
    float *            /* rwork */
);
static PFNLAPACKE_ctbcon_work _g_LAPACKE_ctbcon_work = NULL;
lapack_int LAPACKE_ctbcon_work(
    int            matrix_layout,
    char            norm,
    char            uplo,
    char            diag,
    lapack_int            n,
    lapack_int            kd,
    const lapack_complex_float *            ab,
    lapack_int            ldab,
    float *            rcond,
    lapack_complex_float *            work,
    float *            rwork
)
{
    if(_g_LAPACKE_ctbcon_work==NULL) {
        _g_LAPACKE_ctbcon_work = rindow_load_libopenblas_func("LAPACKE_ctbcon_work"); 
        if(_g_LAPACKE_ctbcon_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctbcon_work(
        matrix_layout,
        norm,
        uplo,
        diag,
        n,
        kd,
        ab,
        ldab,
        rcond,
        work,
        rwork    
    );
}
