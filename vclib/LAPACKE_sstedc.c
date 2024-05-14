#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sstedc not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sstedc)( /* LAPACKE_sstedc */
    int            /* matrix_layout */,
    char            /* compz */,
    lapack_int            /* n */,
    float *            /* d */,
    float *            /* e */,
    float *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_sstedc _g_LAPACKE_sstedc = NULL;
lapack_int LAPACKE_sstedc(
    int            matrix_layout,
    char            compz,
    lapack_int            n,
    float *            d,
    float *            e,
    float *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_sstedc==NULL) {
        _g_LAPACKE_sstedc = rindow_load_libopenblas_func("LAPACKE_sstedc"); 
        if(_g_LAPACKE_sstedc==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sstedc(
        matrix_layout,
        compz,
        n,
        d,
        e,
        z,
        ldz    
    );
}
