#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sggevx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sggevx)( /* LAPACKE_sggevx */
    int            /* matrix_layout */,
    char            /* balanc */,
    char            /* jobvl */,
    char            /* jobvr */,
    char            /* sense */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* alphar */,
    float *            /* alphai */,
    float *            /* beta */,
    float *            /* vl */,
    lapack_int            /* ldvl */,
    float *            /* vr */,
    lapack_int            /* ldvr */,
    lapack_int *            /* ilo */,
    lapack_int *            /* ihi */,
    float *            /* lscale */,
    float *            /* rscale */,
    float *            /* abnrm */,
    float *            /* bbnrm */,
    float *            /* rconde */,
    float *            /* rcondv */
);
static PFNLAPACKE_sggevx _g_LAPACKE_sggevx = NULL;
lapack_int LAPACKE_sggevx(
    int            matrix_layout,
    char            balanc,
    char            jobvl,
    char            jobvr,
    char            sense,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            b,
    lapack_int            ldb,
    float *            alphar,
    float *            alphai,
    float *            beta,
    float *            vl,
    lapack_int            ldvl,
    float *            vr,
    lapack_int            ldvr,
    lapack_int *            ilo,
    lapack_int *            ihi,
    float *            lscale,
    float *            rscale,
    float *            abnrm,
    float *            bbnrm,
    float *            rconde,
    float *            rcondv
)
{
    if(_g_LAPACKE_sggevx==NULL) {
        _g_LAPACKE_sggevx = rindow_load_libopenblas_func("LAPACKE_sggevx"); 
        if(_g_LAPACKE_sggevx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sggevx(
        matrix_layout,
        balanc,
        jobvl,
        jobvr,
        sense,
        n,
        a,
        lda,
        b,
        ldb,
        alphar,
        alphai,
        beta,
        vl,
        ldvl,
        vr,
        ldvr,
        ilo,
        ihi,
        lscale,
        rscale,
        abnrm,
        bbnrm,
        rconde,
        rcondv    
    );
}
