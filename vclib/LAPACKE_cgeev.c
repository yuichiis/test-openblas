#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgeev not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgeev)( /* LAPACKE_cgeev */
    int            /* matrix_layout */,
    char            /* jobvl */,
    char            /* jobvr */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* w */,
    lapack_complex_float *            /* vl */,
    lapack_int            /* ldvl */,
    lapack_complex_float *            /* vr */,
    lapack_int            /* ldvr */
);
static PFNLAPACKE_cgeev _g_LAPACKE_cgeev = NULL;
lapack_int LAPACKE_cgeev(
    int            matrix_layout,
    char            jobvl,
    char            jobvr,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            w,
    lapack_complex_float *            vl,
    lapack_int            ldvl,
    lapack_complex_float *            vr,
    lapack_int            ldvr
)
{
    if(_g_LAPACKE_cgeev==NULL) {
        _g_LAPACKE_cgeev = rindow_load_libopenblas_func("LAPACKE_cgeev"); 
        if(_g_LAPACKE_cgeev==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgeev(
        matrix_layout,
        jobvl,
        jobvr,
        n,
        a,
        lda,
        w,
        vl,
        ldvl,
        vr,
        ldvr    
    );
}
