#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssyevd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssyevd)( /* LAPACKE_ssyevd */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* w */
);
static PFNLAPACKE_ssyevd _g_LAPACKE_ssyevd = NULL;
lapack_int LAPACKE_ssyevd(
    int            matrix_layout,
    char            jobz,
    char            uplo,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            w
)
{
    if(_g_LAPACKE_ssyevd==NULL) {
        _g_LAPACKE_ssyevd = rindow_load_libopenblas_func("LAPACKE_ssyevd"); 
        if(_g_LAPACKE_ssyevd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssyevd(
        matrix_layout,
        jobz,
        uplo,
        n,
        a,
        lda,
        w    
    );
}
