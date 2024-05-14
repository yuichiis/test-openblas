#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dhgeqz_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dhgeqz_work)( /* LAPACKE_dhgeqz_work */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* compq */,
    char            /* compz */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    double *            /* h */,
    lapack_int            /* ldh */,
    double *            /* t */,
    lapack_int            /* ldt */,
    double *            /* alphar */,
    double *            /* alphai */,
    double *            /* beta */,
    double *            /* q */,
    lapack_int            /* ldq */,
    double *            /* z */,
    lapack_int            /* ldz */,
    double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_dhgeqz_work _g_LAPACKE_dhgeqz_work = NULL;
lapack_int LAPACKE_dhgeqz_work(
    int            matrix_layout,
    char            job,
    char            compq,
    char            compz,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    double *            h,
    lapack_int            ldh,
    double *            t,
    lapack_int            ldt,
    double *            alphar,
    double *            alphai,
    double *            beta,
    double *            q,
    lapack_int            ldq,
    double *            z,
    lapack_int            ldz,
    double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_dhgeqz_work==NULL) {
        _g_LAPACKE_dhgeqz_work = rindow_load_libopenblas_func("LAPACKE_dhgeqz_work"); 
        if(_g_LAPACKE_dhgeqz_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dhgeqz_work(
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
        alphar,
        alphai,
        beta,
        q,
        ldq,
        z,
        ldz,
        work,
        lwork    
    );
}
