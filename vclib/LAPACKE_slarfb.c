#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slarfb not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_slarfb)( /* LAPACKE_slarfb */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* trans */,
    char            /* direct */,
    char            /* storev */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const float *            /* v */,
    lapack_int            /* ldv */,
    const float *            /* t */,
    lapack_int            /* ldt */,
    float *            /* c */,
    lapack_int            /* ldc */
);
static PFNLAPACKE_slarfb _g_LAPACKE_slarfb = NULL;
lapack_int LAPACKE_slarfb(
    int            matrix_layout,
    char            side,
    char            trans,
    char            direct,
    char            storev,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    const float *            v,
    lapack_int            ldv,
    const float *            t,
    lapack_int            ldt,
    float *            c,
    lapack_int            ldc
)
{
    if(_g_LAPACKE_slarfb==NULL) {
        _g_LAPACKE_slarfb = rindow_load_libopenblas_func("LAPACKE_slarfb"); 
        if(_g_LAPACKE_slarfb==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slarfb(
        matrix_layout,
        side,
        trans,
        direct,
        storev,
        m,
        n,
        k,
        v,
        ldv,
        t,
        ldt,
        c,
        ldc    
    );
}
