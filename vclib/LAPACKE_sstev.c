#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sstev not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sstev)( /* LAPACKE_sstev */
    int            /* matrix_layout */,
    char            /* jobz */,
    lapack_int            /* n */,
    float *            /* d */,
    float *            /* e */,
    float *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_sstev _g_LAPACKE_sstev = NULL;
lapack_int LAPACKE_sstev(
    int            matrix_layout,
    char            jobz,
    lapack_int            n,
    float *            d,
    float *            e,
    float *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_sstev==NULL) {
        _g_LAPACKE_sstev = rindow_load_libopenblas_func("LAPACKE_sstev"); 
        if(_g_LAPACKE_sstev==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sstev(
        matrix_layout,
        jobz,
        n,
        d,
        e,
        z,
        ldz    
    );
}
