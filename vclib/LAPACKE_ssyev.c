#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ssyev not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ssyev)( /* LAPACKE_ssyev */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* w */
);
static PFNLAPACKE_ssyev _g_LAPACKE_ssyev = NULL;
lapack_int LAPACKE_ssyev(
    int            matrix_layout,
    char            jobz,
    char            uplo,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            w
)
{
    if(_g_LAPACKE_ssyev==NULL) {
        _g_LAPACKE_ssyev = rindow_load_libopenblas_func("LAPACKE_ssyev"); 
        if(_g_LAPACKE_ssyev==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ssyev(
        matrix_layout,
        jobz,
        uplo,
        n,
        a,
        lda,
        w    
    );
}
