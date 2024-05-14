#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgesdd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgesdd)( /* LAPACKE_cgesdd */
    int            /* matrix_layout */,
    char            /* jobz */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    float *            /* s */,
    lapack_complex_float *            /* u */,
    lapack_int            /* ldu */,
    lapack_complex_float *            /* vt */,
    lapack_int            /* ldvt */
);
static PFNLAPACKE_cgesdd _g_LAPACKE_cgesdd = NULL;
lapack_int LAPACKE_cgesdd(
    int            matrix_layout,
    char            jobz,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    float *            s,
    lapack_complex_float *            u,
    lapack_int            ldu,
    lapack_complex_float *            vt,
    lapack_int            ldvt
)
{
    if(_g_LAPACKE_cgesdd==NULL) {
        _g_LAPACKE_cgesdd = rindow_load_libopenblas_func("LAPACKE_cgesdd"); 
        if(_g_LAPACKE_cgesdd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgesdd(
        matrix_layout,
        jobz,
        m,
        n,
        a,
        lda,
        s,
        u,
        ldu,
        vt,
        ldvt    
    );
}
