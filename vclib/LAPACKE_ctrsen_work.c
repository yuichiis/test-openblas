#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctrsen_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctrsen_work)( /* LAPACKE_ctrsen_work */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* compq */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    lapack_complex_float *            /* t */,
    lapack_int            /* ldt */,
    lapack_complex_float *            /* q */,
    lapack_int            /* ldq */,
    lapack_complex_float *            /* w */,
    lapack_int *            /* m */,
    float *            /* s */,
    float *            /* sep */,
    lapack_complex_float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_ctrsen_work _g_LAPACKE_ctrsen_work = NULL;
lapack_int LAPACKE_ctrsen_work(
    int            matrix_layout,
    char            job,
    char            compq,
    const lapack_logical *            select,
    lapack_int            n,
    lapack_complex_float *            t,
    lapack_int            ldt,
    lapack_complex_float *            q,
    lapack_int            ldq,
    lapack_complex_float *            w,
    lapack_int *            m,
    float *            s,
    float *            sep,
    lapack_complex_float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_ctrsen_work==NULL) {
        _g_LAPACKE_ctrsen_work = rindow_load_libopenblas_func("LAPACKE_ctrsen_work"); 
        if(_g_LAPACKE_ctrsen_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctrsen_work(
        matrix_layout,
        job,
        compq,
        select,
        n,
        t,
        ldt,
        q,
        ldq,
        w,
        m,
        s,
        sep,
        work,
        lwork    
    );
}
