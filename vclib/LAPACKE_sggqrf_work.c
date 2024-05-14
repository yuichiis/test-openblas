#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sggqrf_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sggqrf_work)( /* LAPACKE_sggqrf_work */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* taua */,
    float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* taub */,
    float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_sggqrf_work _g_LAPACKE_sggqrf_work = NULL;
lapack_int LAPACKE_sggqrf_work(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            m,
    lapack_int            p,
    float *            a,
    lapack_int            lda,
    float *            taua,
    float *            b,
    lapack_int            ldb,
    float *            taub,
    float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_sggqrf_work==NULL) {
        _g_LAPACKE_sggqrf_work = rindow_load_libopenblas_func("LAPACKE_sggqrf_work"); 
        if(_g_LAPACKE_sggqrf_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sggqrf_work(
        matrix_layout,
        n,
        m,
        p,
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
