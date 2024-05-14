#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgbcon_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgbcon_work)( /* LAPACKE_cgbcon_work */
    int            /* matrix_layout */,
    char            /* norm */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    const lapack_complex_float *            /* ab */,
    lapack_int            /* ldab */,
    const lapack_int *            /* ipiv */,
    float            /* anorm */,
    float *            /* rcond */,
    lapack_complex_float *            /* work */,
    float *            /* rwork */
);
static PFNLAPACKE_cgbcon_work _g_LAPACKE_cgbcon_work = NULL;
lapack_int LAPACKE_cgbcon_work(
    int            matrix_layout,
    char            norm,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    const lapack_complex_float *            ab,
    lapack_int            ldab,
    const lapack_int *            ipiv,
    float            anorm,
    float *            rcond,
    lapack_complex_float *            work,
    float *            rwork
)
{
    if(_g_LAPACKE_cgbcon_work==NULL) {
        _g_LAPACKE_cgbcon_work = rindow_load_libopenblas_func("LAPACKE_cgbcon_work"); 
        if(_g_LAPACKE_cgbcon_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgbcon_work(
        matrix_layout,
        norm,
        n,
        kl,
        ku,
        ab,
        ldab,
        ipiv,
        anorm,
        rcond,
        work,
        rwork    
    );
}
