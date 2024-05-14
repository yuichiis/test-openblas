#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsytrd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsytrd)( /* LAPACKE_dsytrd */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* d */,
    double *            /* e */,
    double *            /* tau */
);
static PFNLAPACKE_dsytrd _g_LAPACKE_dsytrd = NULL;
lapack_int LAPACKE_dsytrd(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            d,
    double *            e,
    double *            tau
)
{
    if(_g_LAPACKE_dsytrd==NULL) {
        _g_LAPACKE_dsytrd = rindow_load_libopenblas_func("LAPACKE_dsytrd"); 
        if(_g_LAPACKE_dsytrd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsytrd(
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
