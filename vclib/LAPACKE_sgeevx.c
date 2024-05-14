#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgeevx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgeevx)( /* LAPACKE_sgeevx */
    int            /* matrix_layout */,
    char            /* balanc */,
    char            /* jobvl */,
    char            /* jobvr */,
    char            /* sense */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* wr */,
    float *            /* wi */,
    float *            /* vl */,
    lapack_int            /* ldvl */,
    float *            /* vr */,
    lapack_int            /* ldvr */,
    lapack_int *            /* ilo */,
    lapack_int *            /* ihi */,
    float *            /* scale */,
    float *            /* abnrm */,
    float *            /* rconde */,
    float *            /* rcondv */
);
static PFNLAPACKE_sgeevx _g_LAPACKE_sgeevx = NULL;
lapack_int LAPACKE_sgeevx(
    int            matrix_layout,
    char            balanc,
    char            jobvl,
    char            jobvr,
    char            sense,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            wr,
    float *            wi,
    float *            vl,
    lapack_int            ldvl,
    float *            vr,
    lapack_int            ldvr,
    lapack_int *            ilo,
    lapack_int *            ihi,
    float *            scale,
    float *            abnrm,
    float *            rconde,
    float *            rcondv
)
{
    if(_g_LAPACKE_sgeevx==NULL) {
        _g_LAPACKE_sgeevx = rindow_load_libopenblas_func("LAPACKE_sgeevx"); 
        if(_g_LAPACKE_sgeevx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgeevx(
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
