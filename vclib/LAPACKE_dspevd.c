#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dspevd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dspevd)( /* LAPACKE_dspevd */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* ap */,
    double *            /* w */,
    double *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_dspevd _g_LAPACKE_dspevd = NULL;
lapack_int LAPACKE_dspevd(
    int            matrix_layout,
    char            jobz,
    char            uplo,
    lapack_int            n,
    double *            ap,
    double *            w,
    double *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_dspevd==NULL) {
        _g_LAPACKE_dspevd = rindow_load_libopenblas_func("LAPACKE_dspevd"); 
        if(_g_LAPACKE_dspevd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dspevd(
        matrix_layout,
        jobz,
        uplo,
        n,
        ap,
        w,
        z,
        ldz    
    );
}
