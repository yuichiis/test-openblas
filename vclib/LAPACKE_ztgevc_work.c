#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztgevc_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztgevc_work)( /* LAPACKE_ztgevc_work */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* howmny */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* s */,
    lapack_int            /* lds */,
    const lapack_complex_double *            /* p */,
    lapack_int            /* ldp */,
    lapack_complex_double *            /* vl */,
    lapack_int            /* ldvl */,
    lapack_complex_double *            /* vr */,
    lapack_int            /* ldvr */,
    lapack_int            /* mm */,
    lapack_int *            /* m */,
    lapack_complex_double *            /* work */,
    double *            /* rwork */
);
static PFNLAPACKE_ztgevc_work _g_LAPACKE_ztgevc_work = NULL;
lapack_int LAPACKE_ztgevc_work(
    int            matrix_layout,
    char            side,
    char            howmny,
    const lapack_logical *            select,
    lapack_int            n,
    const lapack_complex_double *            s,
    lapack_int            lds,
    const lapack_complex_double *            p,
    lapack_int            ldp,
    lapack_complex_double *            vl,
    lapack_int            ldvl,
    lapack_complex_double *            vr,
    lapack_int            ldvr,
    lapack_int            mm,
    lapack_int *            m,
    lapack_complex_double *            work,
    double *            rwork
)
{
    if(_g_LAPACKE_ztgevc_work==NULL) {
        _g_LAPACKE_ztgevc_work = rindow_load_libopenblas_func("LAPACKE_ztgevc_work"); 
        if(_g_LAPACKE_ztgevc_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztgevc_work(
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
