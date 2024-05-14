#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgeev not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgeev)( /* LAPACKE_sgeev */
    int            /* matrix_layout */,
    char            /* jobvl */,
    char            /* jobvr */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* wr */,
    float *            /* wi */,
    float *            /* vl */,
    lapack_int            /* ldvl */,
    float *            /* vr */,
    lapack_int            /* ldvr */
);
static PFNLAPACKE_sgeev _g_LAPACKE_sgeev = NULL;
lapack_int LAPACKE_sgeev(
    int            matrix_layout,
    char            jobvl,
    char            jobvr,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            wr,
    float *            wi,
    float *            vl,
    lapack_int            ldvl,
    float *            vr,
    lapack_int            ldvr
)
{
    if(_g_LAPACKE_sgeev==NULL) {
        _g_LAPACKE_sgeev = rindow_load_libopenblas_func("LAPACKE_sgeev"); 
        if(_g_LAPACKE_sgeev==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgeev(
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
