#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgesvdq not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgesvdq)( /* LAPACKE_dgesvdq */
    int            /* matrix_layout */,
    char            /* joba */,
    char            /* jobp */,
    char            /* jobr */,
    char            /* jobu */,
    char            /* jobv */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* s */,
    double *            /* u */,
    lapack_int            /* ldu */,
    double *            /* v */,
    lapack_int            /* ldv */,
    lapack_int *            /* numrank */
);
static PFNLAPACKE_dgesvdq _g_LAPACKE_dgesvdq = NULL;
lapack_int LAPACKE_dgesvdq(
    int            matrix_layout,
    char            joba,
    char            jobp,
    char            jobr,
    char            jobu,
    char            jobv,
    lapack_int            m,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            s,
    double *            u,
    lapack_int            ldu,
    double *            v,
    lapack_int            ldv,
    lapack_int *            numrank
)
{
    if(_g_LAPACKE_dgesvdq==NULL) {
        _g_LAPACKE_dgesvdq = rindow_load_libopenblas_func("LAPACKE_dgesvdq"); 
        if(_g_LAPACKE_dgesvdq==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgesvdq(
        matrix_layout,
        joba,
        jobp,
        jobr,
        jobu,
        jobv,
        m,
        n,
        a,
        lda,
        s,
        u,
        ldu,
        v,
        ldv,
        numrank    
    );
}
