#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgesvdx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgesvdx)( /* LAPACKE_dgesvdx */
    int            /* matrix_layout */,
    char            /* jobu */,
    char            /* jobvt */,
    char            /* range */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double            /* vl */,
    double            /* vu */,
    lapack_int            /* il */,
    lapack_int            /* iu */,
    lapack_int *            /* ns */,
    double *            /* s */,
    double *            /* u */,
    lapack_int            /* ldu */,
    double *            /* vt */,
    lapack_int            /* ldvt */,
    lapack_int *            /* superb */
);
static PFNLAPACKE_dgesvdx _g_LAPACKE_dgesvdx = NULL;
lapack_int LAPACKE_dgesvdx(
    int            matrix_layout,
    char            jobu,
    char            jobvt,
    char            range,
    lapack_int            m,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double            vl,
    double            vu,
    lapack_int            il,
    lapack_int            iu,
    lapack_int *            ns,
    double *            s,
    double *            u,
    lapack_int            ldu,
    double *            vt,
    lapack_int            ldvt,
    lapack_int *            superb
)
{
    if(_g_LAPACKE_dgesvdx==NULL) {
        _g_LAPACKE_dgesvdx = rindow_load_libopenblas_func("LAPACKE_dgesvdx"); 
        if(_g_LAPACKE_dgesvdx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgesvdx(
        matrix_layout,
        jobu,
        jobvt,
        range,
        m,
        n,
        a,
        lda,
        vl,
        vu,
        il,
        iu,
        ns,
        s,
        u,
        ldu,
        vt,
        ldvt,
        superb    
    );
}
