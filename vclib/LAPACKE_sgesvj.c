#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgesvj not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgesvj)( /* LAPACKE_sgesvj */
    int            /* matrix_layout */,
    char            /* joba */,
    char            /* jobu */,
    char            /* jobv */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* sva */,
    lapack_int            /* mv */,
    float *            /* v */,
    lapack_int            /* ldv */,
    float *            /* stat */
);
static PFNLAPACKE_sgesvj _g_LAPACKE_sgesvj = NULL;
lapack_int LAPACKE_sgesvj(
    int            matrix_layout,
    char            joba,
    char            jobu,
    char            jobv,
    lapack_int            m,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            sva,
    lapack_int            mv,
    float *            v,
    lapack_int            ldv,
    float *            stat
)
{
    if(_g_LAPACKE_sgesvj==NULL) {
        _g_LAPACKE_sgesvj = rindow_load_libopenblas_func("LAPACKE_sgesvj"); 
        if(_g_LAPACKE_sgesvj==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgesvj(
        matrix_layout,
        joba,
        jobu,
        jobv,
        m,
        n,
        a,
        lda,
        sva,
        mv,
        v,
        ldv,
        stat    
    );
}
