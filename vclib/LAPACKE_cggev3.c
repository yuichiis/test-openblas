#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cggev3 not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cggev3)( /* LAPACKE_cggev3 */
    int            /* matrix_layout */,
    char            /* jobvl */,
    char            /* jobvr */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* alpha */,
    lapack_complex_float *            /* beta */,
    lapack_complex_float *            /* vl */,
    lapack_int            /* ldvl */,
    lapack_complex_float *            /* vr */,
    lapack_int            /* ldvr */
);
static PFNLAPACKE_cggev3 _g_LAPACKE_cggev3 = NULL;
lapack_int LAPACKE_cggev3(
    int            matrix_layout,
    char            jobvl,
    char            jobvr,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            alpha,
    lapack_complex_float *            beta,
    lapack_complex_float *            vl,
    lapack_int            ldvl,
    lapack_complex_float *            vr,
    lapack_int            ldvr
)
{
    if(_g_LAPACKE_cggev3==NULL) {
        _g_LAPACKE_cggev3 = rindow_load_libopenblas_func("LAPACKE_cggev3"); 
        if(_g_LAPACKE_cggev3==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cggev3(
        matrix_layout,
        jobvl,
        jobvr,
        n,
        a,
        lda,
        b,
        ldb,
        alpha,
        beta,
        vl,
        ldvl,
        vr,
        ldvr    
    );
}
