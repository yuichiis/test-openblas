#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sopgtr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sopgtr)( /* LAPACKE_sopgtr */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const float *            /* ap */,
    const float *            /* tau */,
    float *            /* q */,
    lapack_int            /* ldq */
);
static PFNLAPACKE_sopgtr _g_LAPACKE_sopgtr = NULL;
lapack_int LAPACKE_sopgtr(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const float *            ap,
    const float *            tau,
    float *            q,
    lapack_int            ldq
)
{
    if(_g_LAPACKE_sopgtr==NULL) {
        _g_LAPACKE_sopgtr = rindow_load_libopenblas_func("LAPACKE_sopgtr"); 
        if(_g_LAPACKE_sopgtr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sopgtr(
        matrix_layout,
        uplo,
        n,
        ap,
        tau,
        q,
        ldq    
    );
}
