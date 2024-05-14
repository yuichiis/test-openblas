#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgesvdx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgesvdx)( /* LAPACKE_sgesvdx */
    int            /* matrix_layout */,
    char            /* jobu */,
    char            /* jobvt */,
    char            /* range */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float            /* vl */,
    float            /* vu */,
    lapack_int            /* il */,
    lapack_int            /* iu */,
    lapack_int *            /* ns */,
    float *            /* s */,
    float *            /* u */,
    lapack_int            /* ldu */,
    float *            /* vt */,
    lapack_int            /* ldvt */,
    lapack_int *            /* superb */
);
static PFNLAPACKE_sgesvdx _g_LAPACKE_sgesvdx = NULL;
lapack_int LAPACKE_sgesvdx(
    int            matrix_layout,
    char            jobu,
    char            jobvt,
    char            range,
    lapack_int            m,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float            vl,
    float            vu,
    lapack_int            il,
    lapack_int            iu,
    lapack_int *            ns,
    float *            s,
    float *            u,
    lapack_int            ldu,
    float *            vt,
    lapack_int            ldvt,
    lapack_int *            superb
)
{
    if(_g_LAPACKE_sgesvdx==NULL) {
        _g_LAPACKE_sgesvdx = rindow_load_libopenblas_func("LAPACKE_sgesvdx"); 
        if(_g_LAPACKE_sgesvdx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgesvdx(
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
