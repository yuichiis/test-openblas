#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zstedc not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zstedc)( /* LAPACKE_zstedc */
    int            /* matrix_layout */,
    char            /* compz */,
    lapack_int            /* n */,
    double *            /* d */,
    double *            /* e */,
    lapack_complex_double *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_zstedc _g_LAPACKE_zstedc = NULL;
lapack_int LAPACKE_zstedc(
    int            matrix_layout,
    char            compz,
    lapack_int            n,
    double *            d,
    double *            e,
    lapack_complex_double *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_zstedc==NULL) {
        _g_LAPACKE_zstedc = rindow_load_libopenblas_func("LAPACKE_zstedc"); 
        if(_g_LAPACKE_zstedc==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zstedc(
        matrix_layout,
        compz,
        n,
        d,
        e,
        z,
        ldz    
    );
}
