#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgejsv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgejsv)( /* LAPACKE_sgejsv */
    int            /* matrix_layout */,
    char            /* joba */,
    char            /* jobu */,
    char            /* jobv */,
    char            /* jobr */,
    char            /* jobt */,
    char            /* jobp */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* sva */,
    float *            /* u */,
    lapack_int            /* ldu */,
    float *            /* v */,
    lapack_int            /* ldv */,
    float *            /* stat */,
    lapack_int *            /* istat */
);
static PFNLAPACKE_sgejsv _g_LAPACKE_sgejsv = NULL;
lapack_int LAPACKE_sgejsv(
    int            matrix_layout,
    char            joba,
    char            jobu,
    char            jobv,
    char            jobr,
    char            jobt,
    char            jobp,
    lapack_int            m,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            sva,
    float *            u,
    lapack_int            ldu,
    float *            v,
    lapack_int            ldv,
    float *            stat,
    lapack_int *            istat
)
{
    if(_g_LAPACKE_sgejsv==NULL) {
        _g_LAPACKE_sgejsv = rindow_load_libopenblas_func("LAPACKE_sgejsv"); 
        if(_g_LAPACKE_sgejsv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgejsv(
        matrix_layout,
        joba,
        jobu,
        jobv,
        jobr,
        jobt,
        jobp,
        m,
        n,
        a,
        lda,
        sva,
        u,
        ldu,
        v,
        ldv,
        stat,
        istat    
    );
}
