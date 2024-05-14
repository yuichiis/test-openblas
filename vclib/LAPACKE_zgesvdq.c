#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgesvdq not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgesvdq)( /* LAPACKE_zgesvdq */
    int            /* matrix_layout */,
    char            /* joba */,
    char            /* jobp */,
    char            /* jobr */,
    char            /* jobu */,
    char            /* jobv */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    double *            /* s */,
    lapack_complex_double *            /* u */,
    lapack_int            /* ldu */,
    lapack_complex_double *            /* v */,
    lapack_int            /* ldv */,
    lapack_int *            /* numrank */
);
static PFNLAPACKE_zgesvdq _g_LAPACKE_zgesvdq = NULL;
lapack_int LAPACKE_zgesvdq(
    int            matrix_layout,
    char            joba,
    char            jobp,
    char            jobr,
    char            jobu,
    char            jobv,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    double *            s,
    lapack_complex_double *            u,
    lapack_int            ldu,
    lapack_complex_double *            v,
    lapack_int            ldv,
    lapack_int *            numrank
)
{
    if(_g_LAPACKE_zgesvdq==NULL) {
        _g_LAPACKE_zgesvdq = rindow_load_libopenblas_func("LAPACKE_zgesvdq"); 
        if(_g_LAPACKE_zgesvdq==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgesvdq(
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
