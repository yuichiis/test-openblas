#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhpevd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhpevd)( /* LAPACKE_zhpevd */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* ap */,
    double *            /* w */,
    lapack_complex_double *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_zhpevd _g_LAPACKE_zhpevd = NULL;
lapack_int LAPACKE_zhpevd(
    int            matrix_layout,
    char            jobz,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            ap,
    double *            w,
    lapack_complex_double *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_zhpevd==NULL) {
        _g_LAPACKE_zhpevd = rindow_load_libopenblas_func("LAPACKE_zhpevd"); 
        if(_g_LAPACKE_zhpevd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhpevd(
        matrix_layout,
        jobz,
        uplo,
        n,
        ap,
        w,
        z,
        ldz    
    );
}
