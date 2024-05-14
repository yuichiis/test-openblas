#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dggev not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dggev)( /* LAPACKE_dggev */
    int            /* matrix_layout */,
    char            /* jobvl */,
    char            /* jobvr */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* alphar */,
    double *            /* alphai */,
    double *            /* beta */,
    double *            /* vl */,
    lapack_int            /* ldvl */,
    double *            /* vr */,
    lapack_int            /* ldvr */
);
static PFNLAPACKE_dggev _g_LAPACKE_dggev = NULL;
lapack_int LAPACKE_dggev(
    int            matrix_layout,
    char            jobvl,
    char            jobvr,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb,
    double *            alphar,
    double *            alphai,
    double *            beta,
    double *            vl,
    lapack_int            ldvl,
    double *            vr,
    lapack_int            ldvr
)
{
    if(_g_LAPACKE_dggev==NULL) {
        _g_LAPACKE_dggev = rindow_load_libopenblas_func("LAPACKE_dggev"); 
        if(_g_LAPACKE_dggev==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dggev(
        matrix_layout,
        jobvl,
        jobvr,
        n,
        a,
        lda,
        b,
        ldb,
        alphar,
        alphai,
        beta,
        vl,
        ldvl,
        vr,
        ldvr    
    );
}
