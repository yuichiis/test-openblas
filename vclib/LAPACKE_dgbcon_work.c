#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgbcon_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgbcon_work)( /* LAPACKE_dgbcon_work */
    int            /* matrix_layout */,
    char            /* norm */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    const double *            /* ab */,
    lapack_int            /* ldab */,
    const lapack_int *            /* ipiv */,
    double            /* anorm */,
    double *            /* rcond */,
    double *            /* work */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_dgbcon_work _g_LAPACKE_dgbcon_work = NULL;
lapack_int LAPACKE_dgbcon_work(
    int            matrix_layout,
    char            norm,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    const double *            ab,
    lapack_int            ldab,
    const lapack_int *            ipiv,
    double            anorm,
    double *            rcond,
    double *            work,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_dgbcon_work==NULL) {
        _g_LAPACKE_dgbcon_work = rindow_load_libopenblas_func("LAPACKE_dgbcon_work"); 
        if(_g_LAPACKE_dgbcon_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgbcon_work(
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
        iwork    
    );
}
