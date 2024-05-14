#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_strsna_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_strsna_work)( /* LAPACKE_strsna_work */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* howmny */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    const float *            /* t */,
    lapack_int            /* ldt */,
    const float *            /* vl */,
    lapack_int            /* ldvl */,
    const float *            /* vr */,
    lapack_int            /* ldvr */,
    float *            /* s */,
    float *            /* sep */,
    lapack_int            /* mm */,
    lapack_int *            /* m */,
    float *            /* work */,
    lapack_int            /* ldwork */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_strsna_work _g_LAPACKE_strsna_work = NULL;
lapack_int LAPACKE_strsna_work(
    int            matrix_layout,
    char            job,
    char            howmny,
    const lapack_logical *            select,
    lapack_int            n,
    const float *            t,
    lapack_int            ldt,
    const float *            vl,
    lapack_int            ldvl,
    const float *            vr,
    lapack_int            ldvr,
    float *            s,
    float *            sep,
    lapack_int            mm,
    lapack_int *            m,
    float *            work,
    lapack_int            ldwork,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_strsna_work==NULL) {
        _g_LAPACKE_strsna_work = rindow_load_libopenblas_func("LAPACKE_strsna_work"); 
        if(_g_LAPACKE_strsna_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_strsna_work(
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
