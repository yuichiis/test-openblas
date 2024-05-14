#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clagsy not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_clagsy)( /* LAPACKE_clagsy */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const float *            /* d */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* iseed */
);
static PFNLAPACKE_clagsy _g_LAPACKE_clagsy = NULL;
lapack_int LAPACKE_clagsy(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            k,
    const float *            d,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_int *            iseed
)
{
    if(_g_LAPACKE_clagsy==NULL) {
        _g_LAPACKE_clagsy = rindow_load_libopenblas_func("LAPACKE_clagsy"); 
        if(_g_LAPACKE_clagsy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clagsy(
        matrix_layout,
        n,
        k,
        d,
        a,
        lda,
        iseed    
    );
}
