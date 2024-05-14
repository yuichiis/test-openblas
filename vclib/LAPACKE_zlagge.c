#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlagge not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zlagge)( /* LAPACKE_zlagge */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    const double *            /* d */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* iseed */
);
static PFNLAPACKE_zlagge _g_LAPACKE_zlagge = NULL;
lapack_int LAPACKE_zlagge(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    const double *            d,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_int *            iseed
)
{
    if(_g_LAPACKE_zlagge==NULL) {
        _g_LAPACKE_zlagge = rindow_load_libopenblas_func("LAPACKE_zlagge"); 
        if(_g_LAPACKE_zlagge==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlagge(
        matrix_layout,
        m,
        n,
        kl,
        ku,
        d,
        a,
        lda,
        iseed    
    );
}
