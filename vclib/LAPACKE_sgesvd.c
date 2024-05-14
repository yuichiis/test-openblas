#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgesvd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgesvd)( /* LAPACKE_sgesvd */
    int            /* matrix_layout */,
    char            /* jobu */,
    char            /* jobvt */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* s */,
    float *            /* u */,
    lapack_int            /* ldu */,
    float *            /* vt */,
    lapack_int            /* ldvt */,
    float *            /* superb */
);
static PFNLAPACKE_sgesvd _g_LAPACKE_sgesvd = NULL;
lapack_int LAPACKE_sgesvd(
    int            matrix_layout,
    char            jobu,
    char            jobvt,
    lapack_int            m,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            s,
    float *            u,
    lapack_int            ldu,
    float *            vt,
    lapack_int            ldvt,
    float *            superb
)
{
    if(_g_LAPACKE_sgesvd==NULL) {
        _g_LAPACKE_sgesvd = rindow_load_libopenblas_func("LAPACKE_sgesvd"); 
        if(_g_LAPACKE_sgesvd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgesvd(
        matrix_layout,
        jobu,
        jobvt,
        m,
        n,
        a,
        lda,
        s,
        u,
        ldu,
        vt,
        ldvt,
        superb    
    );
}
