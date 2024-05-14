#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlarft not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlarft)( /* LAPACKE_dlarft */
    int            /* matrix_layout */,
    char            /* direct */,
    char            /* storev */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const double *            /* v */,
    lapack_int            /* ldv */,
    const double *            /* tau */,
    double *            /* t */,
    lapack_int            /* ldt */
);
static PFNLAPACKE_dlarft _g_LAPACKE_dlarft = NULL;
lapack_int LAPACKE_dlarft(
    int            matrix_layout,
    char            direct,
    char            storev,
    lapack_int            n,
    lapack_int            k,
    const double *            v,
    lapack_int            ldv,
    const double *            tau,
    double *            t,
    lapack_int            ldt
)
{
    if(_g_LAPACKE_dlarft==NULL) {
        _g_LAPACKE_dlarft = rindow_load_libopenblas_func("LAPACKE_dlarft"); 
        if(_g_LAPACKE_dlarft==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlarft(
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
