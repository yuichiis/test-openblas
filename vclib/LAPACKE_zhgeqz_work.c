#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhgeqz_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhgeqz_work)( /* LAPACKE_zhgeqz_work */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* compq */,
    char            /* compz */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    lapack_complex_double *            /* h */,
    lapack_int            /* ldh */,
    lapack_complex_double *            /* t */,
    lapack_int            /* ldt */,
    lapack_complex_double *            /* alpha */,
    lapack_complex_double *            /* beta */,
    lapack_complex_double *            /* q */,
    lapack_int            /* ldq */,
    lapack_complex_double *            /* z */,
    lapack_int            /* ldz */,
    lapack_complex_double *            /* work */,
    lapack_int            /* lwork */,
    double *            /* rwork */
);
static PFNLAPACKE_zhgeqz_work _g_LAPACKE_zhgeqz_work = NULL;
lapack_int LAPACKE_zhgeqz_work(
    int            matrix_layout,
    char            job,
    char            compq,
    char            compz,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    lapack_complex_double *            h,
    lapack_int            ldh,
    lapack_complex_double *            t,
    lapack_int            ldt,
    lapack_complex_double *            alpha,
    lapack_complex_double *            beta,
    lapack_complex_double *            q,
    lapack_int            ldq,
    lapack_complex_double *            z,
    lapack_int            ldz,
    lapack_complex_double *            work,
    lapack_int            lwork,
    double *            rwork
)
{
    if(_g_LAPACKE_zhgeqz_work==NULL) {
        _g_LAPACKE_zhgeqz_work = rindow_load_libopenblas_func("LAPACKE_zhgeqz_work"); 
        if(_g_LAPACKE_zhgeqz_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhgeqz_work(
        matrix_layout,
        job,
        compq,
        compz,
        n,
        ilo,
        ihi,
        h,
        ldh,
        t,
        ldt,
        alpha,
        beta,
        q,
        ldq,
        z,
        ldz,
        work,
        lwork,
        rwork    
    );
}
