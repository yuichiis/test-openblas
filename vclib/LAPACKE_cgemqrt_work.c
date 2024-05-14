#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgemqrt_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgemqrt_work)( /* LAPACKE_cgemqrt_work */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    lapack_int            /* nb */,
    const lapack_complex_float *            /* v */,
    lapack_int            /* ldv */,
    const lapack_complex_float *            /* t */,
    lapack_int            /* ldt */,
    lapack_complex_float *            /* c */,
    lapack_int            /* ldc */,
    lapack_complex_float *            /* work */
);
static PFNLAPACKE_cgemqrt_work _g_LAPACKE_cgemqrt_work = NULL;
lapack_int LAPACKE_cgemqrt_work(
    int            matrix_layout,
    char            side,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    lapack_int            nb,
    const lapack_complex_float *            v,
    lapack_int            ldv,
    const lapack_complex_float *            t,
    lapack_int            ldt,
    lapack_complex_float *            c,
    lapack_int            ldc,
    lapack_complex_float *            work
)
{
    if(_g_LAPACKE_cgemqrt_work==NULL) {
        _g_LAPACKE_cgemqrt_work = rindow_load_libopenblas_func("LAPACKE_cgemqrt_work"); 
        if(_g_LAPACKE_cgemqrt_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgemqrt_work(
        matrix_layout,
        side,
        trans,
        m,
        n,
        k,
        nb,
        v,
        ldv,
        t,
        ldt,
        c,
        ldc,
        work    
    );
}
