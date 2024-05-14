#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtgsna not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtgsna)( /* LAPACKE_dtgsna */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* howmny */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    const double *            /* a */,
    lapack_int            /* lda */,
    const double *            /* b */,
    lapack_int            /* ldb */,
    const double *            /* vl */,
    lapack_int            /* ldvl */,
    const double *            /* vr */,
    lapack_int            /* ldvr */,
    double *            /* s */,
    double *            /* dif */,
    lapack_int            /* mm */,
    lapack_int *            /* m */
);
static PFNLAPACKE_dtgsna _g_LAPACKE_dtgsna = NULL;
lapack_int LAPACKE_dtgsna(
    int            matrix_layout,
    char            job,
    char            howmny,
    const lapack_logical *            select,
    lapack_int            n,
    const double *            a,
    lapack_int            lda,
    const double *            b,
    lapack_int            ldb,
    const double *            vl,
    lapack_int            ldvl,
    const double *            vr,
    lapack_int            ldvr,
    double *            s,
    double *            dif,
    lapack_int            mm,
    lapack_int *            m
)
{
    if(_g_LAPACKE_dtgsna==NULL) {
        _g_LAPACKE_dtgsna = rindow_load_libopenblas_func("LAPACKE_dtgsna"); 
        if(_g_LAPACKE_dtgsna==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtgsna(
        matrix_layout,
        job,
        howmny,
        select,
        n,
        a,
        lda,
        b,
        ldb,
        vl,
        ldvl,
        vr,
        ldvr,
        s,
        dif,
        mm,
        m    
    );
}
