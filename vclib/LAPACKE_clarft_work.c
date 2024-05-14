#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clarft_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_clarft_work)( /* LAPACKE_clarft_work */
    int            /* matrix_layout */,
    char            /* direct */,
    char            /* storev */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const lapack_complex_float *            /* v */,
    lapack_int            /* ldv */,
    const lapack_complex_float *            /* tau */,
    lapack_complex_float *            /* t */,
    lapack_int            /* ldt */
);
static PFNLAPACKE_clarft_work _g_LAPACKE_clarft_work = NULL;
lapack_int LAPACKE_clarft_work(
    int            matrix_layout,
    char            direct,
    char            storev,
    lapack_int            n,
    lapack_int            k,
    const lapack_complex_float *            v,
    lapack_int            ldv,
    const lapack_complex_float *            tau,
    lapack_complex_float *            t,
    lapack_int            ldt
)
{
    if(_g_LAPACKE_clarft_work==NULL) {
        _g_LAPACKE_clarft_work = rindow_load_libopenblas_func("LAPACKE_clarft_work"); 
        if(_g_LAPACKE_clarft_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clarft_work(
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
