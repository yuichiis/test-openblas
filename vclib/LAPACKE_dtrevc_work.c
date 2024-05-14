#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtrevc_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtrevc_work)( /* LAPACKE_dtrevc_work */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* howmny */,
    lapack_logical *            /* select */,
    lapack_int            /* n */,
    const double *            /* t */,
    lapack_int            /* ldt */,
    double *            /* vl */,
    lapack_int            /* ldvl */,
    double *            /* vr */,
    lapack_int            /* ldvr */,
    lapack_int            /* mm */,
    lapack_int *            /* m */,
    double *            /* work */
);
static PFNLAPACKE_dtrevc_work _g_LAPACKE_dtrevc_work = NULL;
lapack_int LAPACKE_dtrevc_work(
    int            matrix_layout,
    char            side,
    char            howmny,
    lapack_logical *            select,
    lapack_int            n,
    const double *            t,
    lapack_int            ldt,
    double *            vl,
    lapack_int            ldvl,
    double *            vr,
    lapack_int            ldvr,
    lapack_int            mm,
    lapack_int *            m,
    double *            work
)
{
    if(_g_LAPACKE_dtrevc_work==NULL) {
        _g_LAPACKE_dtrevc_work = rindow_load_libopenblas_func("LAPACKE_dtrevc_work"); 
        if(_g_LAPACKE_dtrevc_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtrevc_work(
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
        work    
    );
}
