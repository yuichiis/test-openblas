#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlarft_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zlarft_work)( /* LAPACKE_zlarft_work */
    int            /* matrix_layout */,
    char            /* direct */,
    char            /* storev */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const lapack_complex_double *            /* v */,
    lapack_int            /* ldv */,
    const lapack_complex_double *            /* tau */,
    lapack_complex_double *            /* t */,
    lapack_int            /* ldt */
);
static PFNLAPACKE_zlarft_work _g_LAPACKE_zlarft_work = NULL;
lapack_int LAPACKE_zlarft_work(
    int            matrix_layout,
    char            direct,
    char            storev,
    lapack_int            n,
    lapack_int            k,
    const lapack_complex_double *            v,
    lapack_int            ldv,
    const lapack_complex_double *            tau,
    lapack_complex_double *            t,
    lapack_int            ldt
)
{
    if(_g_LAPACKE_zlarft_work==NULL) {
        _g_LAPACKE_zlarft_work = rindow_load_libopenblas_func("LAPACKE_zlarft_work"); 
        if(_g_LAPACKE_zlarft_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlarft_work(
        matrix_layout,
        direct,
        storev,
        n,
        k,
        v,
        ldv,
        tau,
        t,
        ldt    
    );
}
