#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dsyev not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dsyev)( /* LAPACKE_dsyev */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* w */
);
static PFNLAPACKE_dsyev _g_LAPACKE_dsyev = NULL;
lapack_int LAPACKE_dsyev(
    int            matrix_layout,
    char            jobz,
    char            uplo,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            w
)
{
    if(_g_LAPACKE_dsyev==NULL) {
        _g_LAPACKE_dsyev = rindow_load_libopenblas_func("LAPACKE_dsyev"); 
        if(_g_LAPACKE_dsyev==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dsyev(
        matrix_layout,
        jobz,
        uplo,
        n,
        a,
        lda,
        w    
    );
}
