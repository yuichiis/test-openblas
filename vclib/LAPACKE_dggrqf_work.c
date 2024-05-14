#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dggrqf_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dggrqf_work)( /* LAPACKE_dggrqf_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* taua */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* taub */,
    double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_dggrqf_work _g_LAPACKE_dggrqf_work = NULL;
lapack_int LAPACKE_dggrqf_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            p,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            taua,
    double *            b,
    lapack_int            ldb,
    double *            taub,
    double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_dggrqf_work==NULL) {
        _g_LAPACKE_dggrqf_work = rindow_load_libopenblas_func("LAPACKE_dggrqf_work"); 
        if(_g_LAPACKE_dggrqf_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dggrqf_work(
        matrix_layout,
        m,
        p,
        n,
        a,
        lda,
        taua,
        b,
        ldb,
        taub,
        work,
        lwork    
    );
}
