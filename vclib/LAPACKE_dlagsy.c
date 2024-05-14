#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlagsy not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlagsy)( /* LAPACKE_dlagsy */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const double *            /* d */,
    double *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* iseed */
);
static PFNLAPACKE_dlagsy _g_LAPACKE_dlagsy = NULL;
lapack_int LAPACKE_dlagsy(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            k,
    const double *            d,
    double *            a,
    lapack_int            lda,
    lapack_int *            iseed
)
{
    if(_g_LAPACKE_dlagsy==NULL) {
        _g_LAPACKE_dlagsy = rindow_load_libopenblas_func("LAPACKE_dlagsy"); 
        if(_g_LAPACKE_dlagsy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlagsy(
        matrix_layout,
        n,
        k,
        d,
        a,
        lda,
        iseed    
    );
}
