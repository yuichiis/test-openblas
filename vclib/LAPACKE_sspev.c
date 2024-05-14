#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sspev not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sspev)( /* LAPACKE_sspev */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* ap */,
    float *            /* w */,
    float *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_sspev _g_LAPACKE_sspev = NULL;
lapack_int LAPACKE_sspev(
    int            matrix_layout,
    char            jobz,
    char            uplo,
    lapack_int            n,
    float *            ap,
    float *            w,
    float *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_sspev==NULL) {
        _g_LAPACKE_sspev = rindow_load_libopenblas_func("LAPACKE_sspev"); 
        if(_g_LAPACKE_sspev==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sspev(
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
