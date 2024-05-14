#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgeevx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgeevx)( /* LAPACKE_dgeevx */
    int            /* matrix_layout */,
    char            /* balanc */,
    char            /* jobvl */,
    char            /* jobvr */,
    char            /* sense */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* wr */,
    double *            /* wi */,
    double *            /* vl */,
    lapack_int            /* ldvl */,
    double *            /* vr */,
    lapack_int            /* ldvr */,
    lapack_int *            /* ilo */,
    lapack_int *            /* ihi */,
    double *            /* scale */,
    double *            /* abnrm */,
    double *            /* rconde */,
    double *            /* rcondv */
);
static PFNLAPACKE_dgeevx _g_LAPACKE_dgeevx = NULL;
lapack_int LAPACKE_dgeevx(
    int            matrix_layout,
    char            balanc,
    char            jobvl,
    char            jobvr,
    char            sense,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            wr,
    double *            wi,
    double *            vl,
    lapack_int            ldvl,
    double *            vr,
    lapack_int            ldvr,
    lapack_int *            ilo,
    lapack_int *            ihi,
    double *            scale,
    double *            abnrm,
    double *            rconde,
    double *            rcondv
)
{
    if(_g_LAPACKE_dgeevx==NULL) {
        _g_LAPACKE_dgeevx = rindow_load_libopenblas_func("LAPACKE_dgeevx"); 
        if(_g_LAPACKE_dgeevx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgeevx(
        matrix_layout,
        balanc,
        jobvl,
        jobvr,
        sense,
        n,
        a,
        lda,
        wr,
        wi,
        vl,
        ldvl,
        vr,
        ldvr,
        ilo,
        ihi,
        scale,
        abnrm,
        rconde,
        rcondv    
    );
}
