#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chsein not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chsein)( /* LAPACKE_chsein */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* eigsrc */,
    char            /* initv */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* h */,
    lapack_int            /* ldh */,
    lapack_complex_float *            /* w */,
    lapack_complex_float *            /* vl */,
    lapack_int            /* ldvl */,
    lapack_complex_float *            /* vr */,
    lapack_int            /* ldvr */,
    lapack_int            /* mm */,
    lapack_int *            /* m */,
    lapack_int *            /* ifaill */,
    lapack_int *            /* ifailr */
);
static PFNLAPACKE_chsein _g_LAPACKE_chsein = NULL;
lapack_int LAPACKE_chsein(
    int            matrix_layout,
    char            job,
    char            eigsrc,
    char            initv,
    const lapack_logical *            select,
    lapack_int            n,
    const lapack_complex_float *            h,
    lapack_int            ldh,
    lapack_complex_float *            w,
    lapack_complex_float *            vl,
    lapack_int            ldvl,
    lapack_complex_float *            vr,
    lapack_int            ldvr,
    lapack_int            mm,
    lapack_int *            m,
    lapack_int *            ifaill,
    lapack_int *            ifailr
)
{
    if(_g_LAPACKE_chsein==NULL) {
        _g_LAPACKE_chsein = rindow_load_libopenblas_func("LAPACKE_chsein"); 
        if(_g_LAPACKE_chsein==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chsein(
        matrix_layout,
        job,
        eigsrc,
        initv,
        select,
        n,
        h,
        ldh,
        w,
        vl,
        ldvl,
        vr,
        ldvr,
        mm,
        m,
        ifaill,
        ifailr    
    );
}
