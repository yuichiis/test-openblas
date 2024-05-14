#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgejsv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgejsv)( /* LAPACKE_dgejsv */
    int            /* matrix_layout */,
    char            /* joba */,
    char            /* jobu */,
    char            /* jobv */,
    char            /* jobr */,
    char            /* jobt */,
    char            /* jobp */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* sva */,
    double *            /* u */,
    lapack_int            /* ldu */,
    double *            /* v */,
    lapack_int            /* ldv */,
    double *            /* stat */,
    lapack_int *            /* istat */
);
static PFNLAPACKE_dgejsv _g_LAPACKE_dgejsv = NULL;
lapack_int LAPACKE_dgejsv(
    int            matrix_layout,
    char            joba,
    char            jobu,
    char            jobv,
    char            jobr,
    char            jobt,
    char            jobp,
    lapack_int            m,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            sva,
    double *            u,
    lapack_int            ldu,
    double *            v,
    lapack_int            ldv,
    double *            stat,
    lapack_int *            istat
)
{
    if(_g_LAPACKE_dgejsv==NULL) {
        _g_LAPACKE_dgejsv = rindow_load_libopenblas_func("LAPACKE_dgejsv"); 
        if(_g_LAPACKE_dgejsv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgejsv(
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
