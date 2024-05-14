#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cheevd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cheevd)( /* LAPACKE_cheevd */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    float *            /* w */
);
static PFNLAPACKE_cheevd _g_LAPACKE_cheevd = NULL;
lapack_int LAPACKE_cheevd(
    int            matrix_layout,
    char            jobz,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    float *            w
)
{
    if(_g_LAPACKE_cheevd==NULL) {
        _g_LAPACKE_cheevd = rindow_load_libopenblas_func("LAPACKE_cheevd"); 
        if(_g_LAPACKE_cheevd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cheevd(
        matrix_layout,
        jobz,
        uplo,
        n,
        a,
        lda,
        w    
    );
}
