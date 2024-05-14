#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctgevc_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctgevc_work)( /* LAPACKE_ctgevc_work */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* howmny */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* s */,
    lapack_int            /* lds */,
    const lapack_complex_float *            /* p */,
    lapack_int            /* ldp */,
    lapack_complex_float *            /* vl */,
    lapack_int            /* ldvl */,
    lapack_complex_float *            /* vr */,
    lapack_int            /* ldvr */,
    lapack_int            /* mm */,
    lapack_int *            /* m */,
    lapack_complex_float *            /* work */,
    float *            /* rwork */
);
static PFNLAPACKE_ctgevc_work _g_LAPACKE_ctgevc_work = NULL;
lapack_int LAPACKE_ctgevc_work(
    int            matrix_layout,
    char            side,
    char            howmny,
    const lapack_logical *            select,
    lapack_int            n,
    const lapack_complex_float *            s,
    lapack_int            lds,
    const lapack_complex_float *            p,
    lapack_int            ldp,
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
    if(_g_LAPACKE_ctgevc_work==NULL) {
        _g_LAPACKE_ctgevc_work = rindow_load_libopenblas_func("LAPACKE_ctgevc_work"); 
        if(_g_LAPACKE_ctgevc_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctgevc_work(
        matrix_layout,
        side,
        howmny,
        select,
        n,
        s,
        lds,
        p,
        ldp,
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
