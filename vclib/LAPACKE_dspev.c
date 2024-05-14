#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dspev not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dspev)( /* LAPACKE_dspev */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* ap */,
    double *            /* w */,
    double *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_dspev _g_LAPACKE_dspev = NULL;
lapack_int LAPACKE_dspev(
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
    if(_g_LAPACKE_dspev==NULL) {
        _g_LAPACKE_dspev = rindow_load_libopenblas_func("LAPACKE_dspev"); 
        if(_g_LAPACKE_dspev==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dspev(
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
