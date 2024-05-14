#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clarft not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_clarft)( /* LAPACKE_clarft */
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
static PFNLAPACKE_clarft _g_LAPACKE_clarft = NULL;
lapack_int LAPACKE_clarft(
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
    if(_g_LAPACKE_clarft==NULL) {
        _g_LAPACKE_clarft = rindow_load_libopenblas_func("LAPACKE_clarft"); 
        if(_g_LAPACKE_clarft==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clarft(
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
