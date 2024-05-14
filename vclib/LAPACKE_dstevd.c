#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dstevd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dstevd)( /* LAPACKE_dstevd */
    int            /* matrix_layout */,
    char            /* jobz */,
    lapack_int            /* n */,
    double *            /* d */,
    double *            /* e */,
    double *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_dstevd _g_LAPACKE_dstevd = NULL;
lapack_int LAPACKE_dstevd(
    int            matrix_layout,
    char            jobz,
    lapack_int            n,
    double *            d,
    double *            e,
    double *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_dstevd==NULL) {
        _g_LAPACKE_dstevd = rindow_load_libopenblas_func("LAPACKE_dstevd"); 
        if(_g_LAPACKE_dstevd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dstevd(
        matrix_layout,
        jobz,
        n,
        d,
        e,
        z,
        ldz    
    );
}
