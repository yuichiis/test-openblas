#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztrsna not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztrsna)( /* LAPACKE_ztrsna */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* howmny */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* t */,
    lapack_int            /* ldt */,
    const lapack_complex_double *            /* vl */,
    lapack_int            /* ldvl */,
    const lapack_complex_double *            /* vr */,
    lapack_int            /* ldvr */,
    double *            /* s */,
    double *            /* sep */,
    lapack_int            /* mm */,
    lapack_int *            /* m */
);
static PFNLAPACKE_ztrsna _g_LAPACKE_ztrsna = NULL;
lapack_int LAPACKE_ztrsna(
    int            matrix_layout,
    char            job,
    char            howmny,
    const lapack_logical *            select,
    lapack_int            n,
    const lapack_complex_double *            t,
    lapack_int            ldt,
    const lapack_complex_double *            vl,
    lapack_int            ldvl,
    const lapack_complex_double *            vr,
    lapack_int            ldvr,
    double *            s,
    double *            sep,
    lapack_int            mm,
    lapack_int *            m
)
{
    if(_g_LAPACKE_ztrsna==NULL) {
        _g_LAPACKE_ztrsna = rindow_load_libopenblas_func("LAPACKE_ztrsna"); 
        if(_g_LAPACKE_ztrsna==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztrsna(
        matrix_layout,
        job,
        howmny,
        select,
        n,
        t,
        ldt,
        vl,
        ldvl,
        vr,
        ldvr,
        s,
        sep,
        mm,
        m    
    );
}
