#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_stgevc not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_stgevc)( /* LAPACKE_stgevc */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* howmny */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    const float *            /* s */,
    lapack_int            /* lds */,
    const float *            /* p */,
    lapack_int            /* ldp */,
    float *            /* vl */,
    lapack_int            /* ldvl */,
    float *            /* vr */,
    lapack_int            /* ldvr */,
    lapack_int            /* mm */,
    lapack_int *            /* m */
);
static PFNLAPACKE_stgevc _g_LAPACKE_stgevc = NULL;
lapack_int LAPACKE_stgevc(
    int            matrix_layout,
    char            side,
    char            howmny,
    const lapack_logical *            select,
    lapack_int            n,
    const float *            s,
    lapack_int            lds,
    const float *            p,
    lapack_int            ldp,
    float *            vl,
    lapack_int            ldvl,
    float *            vr,
    lapack_int            ldvr,
    lapack_int            mm,
    lapack_int *            m
)
{
    if(_g_LAPACKE_stgevc==NULL) {
        _g_LAPACKE_stgevc = rindow_load_libopenblas_func("LAPACKE_stgevc"); 
        if(_g_LAPACKE_stgevc==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_stgevc(
        matrix_layout,
        side,
        howmny,
        select,
        n,
        s,
        lds,
        p,
        ldp,
        vl,
        ldvl,
        vr,
        ldvr,
        mm,
        m    
    );
}
