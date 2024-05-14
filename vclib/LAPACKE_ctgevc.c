#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctgevc not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctgevc)( /* LAPACKE_ctgevc */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* howmny */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* s */,
    lapack_int            /* lds */,
    const lapack_complex_float *            /* p */,
    lapack_int            /* ldp */,
    lapack_complex_float *            /* vl */,
    lapack_int            /* ldvl */,
    lapack_complex_float *            /* vr */,
    lapack_int            /* ldvr */,
    lapack_int            /* mm */,
    lapack_int *            /* m */
);
static PFNLAPACKE_ctgevc _g_LAPACKE_ctgevc = NULL;
lapack_int LAPACKE_ctgevc(
    int            matrix_layout,
    char            side,
    char            howmny,
    const lapack_logical *            select,
    lapack_int            n,
    const lapack_complex_float *            s,
    lapack_int            lds,
    const lapack_complex_float *            p,
    lapack_int            ldp,
    lapack_complex_float *            vl,
    lapack_int            ldvl,
    lapack_complex_float *            vr,
    lapack_int            ldvr,
    lapack_int            mm,
    lapack_int *            m
)
{
    if(_g_LAPACKE_ctgevc==NULL) {
        _g_LAPACKE_ctgevc = rindow_load_libopenblas_func("LAPACKE_ctgevc"); 
        if(_g_LAPACKE_ctgevc==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctgevc(
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
