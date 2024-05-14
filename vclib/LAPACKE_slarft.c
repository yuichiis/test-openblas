#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slarft not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_slarft)( /* LAPACKE_slarft */
    int            /* matrix_layout */,
    char            /* direct */,
    char            /* storev */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const float *            /* v */,
    lapack_int            /* ldv */,
    const float *            /* tau */,
    float *            /* t */,
    lapack_int            /* ldt */
);
static PFNLAPACKE_slarft _g_LAPACKE_slarft = NULL;
lapack_int LAPACKE_slarft(
    int            matrix_layout,
    char            direct,
    char            storev,
    lapack_int            n,
    lapack_int            k,
    const float *            v,
    lapack_int            ldv,
    const float *            tau,
    float *            t,
    lapack_int            ldt
)
{
    if(_g_LAPACKE_slarft==NULL) {
        _g_LAPACKE_slarft = rindow_load_libopenblas_func("LAPACKE_slarft"); 
        if(_g_LAPACKE_slarft==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slarft(
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
