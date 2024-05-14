#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhetrd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhetrd)( /* LAPACKE_zhetrd */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    double *            /* d */,
    double *            /* e */,
    lapack_complex_double *            /* tau */
);
static PFNLAPACKE_zhetrd _g_LAPACKE_zhetrd = NULL;
lapack_int LAPACKE_zhetrd(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    double *            d,
    double *            e,
    lapack_complex_double *            tau
)
{
    if(_g_LAPACKE_zhetrd==NULL) {
        _g_LAPACKE_zhetrd = rindow_load_libopenblas_func("LAPACKE_zhetrd"); 
        if(_g_LAPACKE_zhetrd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhetrd(
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
