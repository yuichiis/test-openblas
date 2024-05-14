#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chetrd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chetrd)( /* LAPACKE_chetrd */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    float *            /* d */,
    float *            /* e */,
    lapack_complex_float *            /* tau */
);
static PFNLAPACKE_chetrd _g_LAPACKE_chetrd = NULL;
lapack_int LAPACKE_chetrd(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    float *            d,
    float *            e,
    lapack_complex_float *            tau
)
{
    if(_g_LAPACKE_chetrd==NULL) {
        _g_LAPACKE_chetrd = rindow_load_libopenblas_func("LAPACKE_chetrd"); 
        if(_g_LAPACKE_chetrd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chetrd(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        d,
        e,
        tau    
    );
}
