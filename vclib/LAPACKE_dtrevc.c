#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtrevc not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtrevc)( /* LAPACKE_dtrevc */
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
    lapack_int *            /* m */
);
static PFNLAPACKE_dtrevc _g_LAPACKE_dtrevc = NULL;
lapack_int LAPACKE_dtrevc(
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
    lapack_int *            m
)
{
    if(_g_LAPACKE_dtrevc==NULL) {
        _g_LAPACKE_dtrevc = rindow_load_libopenblas_func("LAPACKE_dtrevc"); 
        if(_g_LAPACKE_dtrevc==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtrevc(
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
        m    
    );
}
