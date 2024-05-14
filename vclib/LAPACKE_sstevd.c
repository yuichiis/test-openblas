#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sstevd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sstevd)( /* LAPACKE_sstevd */
    int            /* matrix_layout */,
    char            /* jobz */,
    lapack_int            /* n */,
    float *            /* d */,
    float *            /* e */,
    float *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_sstevd _g_LAPACKE_sstevd = NULL;
lapack_int LAPACKE_sstevd(
    int            matrix_layout,
    char            jobz,
    lapack_int            n,
    float *            d,
    float *            e,
    float *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_sstevd==NULL) {
        _g_LAPACKE_sstevd = rindow_load_libopenblas_func("LAPACKE_sstevd"); 
        if(_g_LAPACKE_sstevd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sstevd(
        matrix_layout,
        jobz,
        n,
        d,
        e,
        z,
        ldz    
    );
}
