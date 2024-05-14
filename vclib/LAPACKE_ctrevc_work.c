#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctrevc_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctrevc_work)( /* LAPACKE_ctrevc_work */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* howmny */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    lapack_complex_float *            /* t */,
    lapack_int            /* ldt */,
    lapack_complex_float *            /* vl */,
    lapack_int            /* ldvl */,
    lapack_complex_float *            /* vr */,
    lapack_int            /* ldvr */,
    lapack_int            /* mm */,
    lapack_int *            /* m */,
    lapack_complex_float *            /* work */,
    float *            /* rwork */
);
static PFNLAPACKE_ctrevc_work _g_LAPACKE_ctrevc_work = NULL;
lapack_int LAPACKE_ctrevc_work(
    int            matrix_layout,
    char            side,
    char            howmny,
    const lapack_logical *            select,
    lapack_int            n,
    lapack_complex_float *            t,
    lapack_int            ldt,
    lapack_complex_float *            vl,
    lapack_int            ldvl,
    lapack_complex_float *            vr,
    lapack_int            ldvr,
    lapack_int            mm,
    lapack_int *            m,
    lapack_complex_float *            work,
    float *            rwork
)
{
    if(_g_LAPACKE_ctrevc_work==NULL) {
        _g_LAPACKE_ctrevc_work = rindow_load_libopenblas_func("LAPACKE_ctrevc_work"); 
        if(_g_LAPACKE_ctrevc_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctrevc_work(
        matrix_layout,
        side,
        howmny,
        select,
        n,
        t,
        ldt,
        vl,
        ldvl,
        vr,
        ldvr,
        mm,
        m,
        work,
        rwork    
    );
}
