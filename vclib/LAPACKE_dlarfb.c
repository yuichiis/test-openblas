#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlarfb not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlarfb)( /* LAPACKE_dlarfb */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* trans */,
    char            /* direct */,
    char            /* storev */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const double *            /* v */,
    lapack_int            /* ldv */,
    const double *            /* t */,
    lapack_int            /* ldt */,
    double *            /* c */,
    lapack_int            /* ldc */
);
static PFNLAPACKE_dlarfb _g_LAPACKE_dlarfb = NULL;
lapack_int LAPACKE_dlarfb(
    int            matrix_layout,
    char            side,
    char            trans,
    char            direct,
    char            storev,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    const double *            v,
    lapack_int            ldv,
    const double *            t,
    lapack_int            ldt,
    double *            c,
    lapack_int            ldc
)
{
    if(_g_LAPACKE_dlarfb==NULL) {
        _g_LAPACKE_dlarfb = rindow_load_libopenblas_func("LAPACKE_dlarfb"); 
        if(_g_LAPACKE_dlarfb==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlarfb(
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
