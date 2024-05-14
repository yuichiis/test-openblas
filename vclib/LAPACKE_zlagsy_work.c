#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlagsy_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zlagsy_work)( /* LAPACKE_zlagsy_work */
    int            /* matrix_layout */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const double *            /* d */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* iseed */,
    lapack_complex_double *            /* work */
);
static PFNLAPACKE_zlagsy_work _g_LAPACKE_zlagsy_work = NULL;
lapack_int LAPACKE_zlagsy_work(
    int            matrix_layout,
    lapack_int            n,
    lapack_int            k,
    const double *            d,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_int *            iseed,
    lapack_complex_double *            work
)
{
    if(_g_LAPACKE_zlagsy_work==NULL) {
        _g_LAPACKE_zlagsy_work = rindow_load_libopenblas_func("LAPACKE_zlagsy_work"); 
        if(_g_LAPACKE_zlagsy_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlagsy_work(
        matrix_layout,
        n,
        k,
        d,
        a,
        lda,
        iseed,
        work    
    );
}
