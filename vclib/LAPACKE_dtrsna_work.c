#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtrsna_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtrsna_work)( /* LAPACKE_dtrsna_work */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* howmny */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    const double *            /* t */,
    lapack_int            /* ldt */,
    const double *            /* vl */,
    lapack_int            /* ldvl */,
    const double *            /* vr */,
    lapack_int            /* ldvr */,
    double *            /* s */,
    double *            /* sep */,
    lapack_int            /* mm */,
    lapack_int *            /* m */,
    double *            /* work */,
    lapack_int            /* ldwork */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_dtrsna_work _g_LAPACKE_dtrsna_work = NULL;
lapack_int LAPACKE_dtrsna_work(
    int            matrix_layout,
    char            job,
    char            howmny,
    const lapack_logical *            select,
    lapack_int            n,
    const double *            t,
    lapack_int            ldt,
    const double *            vl,
    lapack_int            ldvl,
    const double *            vr,
    lapack_int            ldvr,
    double *            s,
    double *            sep,
    lapack_int            mm,
    lapack_int *            m,
    double *            work,
    lapack_int            ldwork,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_dtrsna_work==NULL) {
        _g_LAPACKE_dtrsna_work = rindow_load_libopenblas_func("LAPACKE_dtrsna_work"); 
        if(_g_LAPACKE_dtrsna_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtrsna_work(
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
        m,
        work,
        ldwork,
        iwork    
    );
}
