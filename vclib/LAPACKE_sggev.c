#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sggev not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sggev)( /* LAPACKE_sggev */
    int            /* matrix_layout */,
    char            /* jobvl */,
    char            /* jobvr */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* alphar */,
    float *            /* alphai */,
    float *            /* beta */,
    float *            /* vl */,
    lapack_int            /* ldvl */,
    float *            /* vr */,
    lapack_int            /* ldvr */
);
static PFNLAPACKE_sggev _g_LAPACKE_sggev = NULL;
lapack_int LAPACKE_sggev(
    int            matrix_layout,
    char            jobvl,
    char            jobvr,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            b,
    lapack_int            ldb,
    float *            alphar,
    float *            alphai,
    float *            beta,
    float *            vl,
    lapack_int            ldvl,
    float *            vr,
    lapack_int            ldvr
)
{
    if(_g_LAPACKE_sggev==NULL) {
        _g_LAPACKE_sggev = rindow_load_libopenblas_func("LAPACKE_sggev"); 
        if(_g_LAPACKE_sggev==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sggev(
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
