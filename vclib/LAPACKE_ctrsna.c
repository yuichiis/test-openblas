#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctrsna not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctrsna)( /* LAPACKE_ctrsna */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* howmny */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* t */,
    lapack_int            /* ldt */,
    const lapack_complex_float *            /* vl */,
    lapack_int            /* ldvl */,
    const lapack_complex_float *            /* vr */,
    lapack_int            /* ldvr */,
    float *            /* s */,
    float *            /* sep */,
    lapack_int            /* mm */,
    lapack_int *            /* m */
);
static PFNLAPACKE_ctrsna _g_LAPACKE_ctrsna = NULL;
lapack_int LAPACKE_ctrsna(
    int            matrix_layout,
    char            job,
    char            howmny,
    const lapack_logical *            select,
    lapack_int            n,
    const lapack_complex_float *            t,
    lapack_int            ldt,
    const lapack_complex_float *            vl,
    lapack_int            ldvl,
    const lapack_complex_float *            vr,
    lapack_int            ldvr,
    float *            s,
    float *            sep,
    lapack_int            mm,
    lapack_int *            m
)
{
    if(_g_LAPACKE_ctrsna==NULL) {
        _g_LAPACKE_ctrsna = rindow_load_libopenblas_func("LAPACKE_ctrsna"); 
        if(_g_LAPACKE_ctrsna==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctrsna(
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
