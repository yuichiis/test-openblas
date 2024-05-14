#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cggrqf_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cggrqf_work)( /* LAPACKE_cggrqf_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* taua */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* taub */,
    lapack_complex_float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_cggrqf_work _g_LAPACKE_cggrqf_work = NULL;
lapack_int LAPACKE_cggrqf_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            p,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            taua,
    lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            taub,
    lapack_complex_float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_cggrqf_work==NULL) {
        _g_LAPACKE_cggrqf_work = rindow_load_libopenblas_func("LAPACKE_cggrqf_work"); 
        if(_g_LAPACKE_cggrqf_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cggrqf_work(
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
