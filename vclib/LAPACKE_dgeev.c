#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgeev not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgeev)( /* LAPACKE_dgeev */
    int            /* matrix_layout */,
    char            /* jobvl */,
    char            /* jobvr */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* wr */,
    double *            /* wi */,
    double *            /* vl */,
    lapack_int            /* ldvl */,
    double *            /* vr */,
    lapack_int            /* ldvr */
);
static PFNLAPACKE_dgeev _g_LAPACKE_dgeev = NULL;
lapack_int LAPACKE_dgeev(
    int            matrix_layout,
    char            jobvl,
    char            jobvr,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            wr,
    double *            wi,
    double *            vl,
    lapack_int            ldvl,
    double *            vr,
    lapack_int            ldvr
)
{
    if(_g_LAPACKE_dgeev==NULL) {
        _g_LAPACKE_dgeev = rindow_load_libopenblas_func("LAPACKE_dgeev"); 
        if(_g_LAPACKE_dgeev==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgeev(
        matrix_layout,
        jobvl,
        jobvr,
        n,
        a,
        lda,
        wr,
        wi,
        vl,
        ldvl,
        vr,
        ldvr    
    );
}
