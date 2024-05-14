#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgesdd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgesdd)( /* LAPACKE_zgesdd */
    int            /* matrix_layout */,
    char            /* jobz */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    double *            /* s */,
    lapack_complex_double *            /* u */,
    lapack_int            /* ldu */,
    lapack_complex_double *            /* vt */,
    lapack_int            /* ldvt */
);
static PFNLAPACKE_zgesdd _g_LAPACKE_zgesdd = NULL;
lapack_int LAPACKE_zgesdd(
    int            matrix_layout,
    char            jobz,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    double *            s,
    lapack_complex_double *            u,
    lapack_int            ldu,
    lapack_complex_double *            vt,
    lapack_int            ldvt
)
{
    if(_g_LAPACKE_zgesdd==NULL) {
        _g_LAPACKE_zgesdd = rindow_load_libopenblas_func("LAPACKE_zgesdd"); 
        if(_g_LAPACKE_zgesdd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgesdd(
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
