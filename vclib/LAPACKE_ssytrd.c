#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssytrd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssytrd)( /* LAPACKE_ssytrd */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* d */,
    float *            /* e */,
    float *            /* tau */
);
static PFNLAPACKE_ssytrd _g_LAPACKE_ssytrd = NULL;
lapack_int LAPACKE_ssytrd(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            d,
    float *            e,
    float *            tau
)
{
    if(_g_LAPACKE_ssytrd==NULL) {
        _g_LAPACKE_ssytrd = rindow_load_libopenblas_func("LAPACKE_ssytrd"); 
        if(_g_LAPACKE_ssytrd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssytrd(
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
