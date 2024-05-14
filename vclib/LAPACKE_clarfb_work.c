#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clarfb_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_clarfb_work)( /* LAPACKE_clarfb_work */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* trans */,
    char            /* direct */,
    char            /* storev */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const lapack_complex_float *            /* v */,
    lapack_int            /* ldv */,
    const lapack_complex_float *            /* t */,
    lapack_int            /* ldt */,
    lapack_complex_float *            /* c */,
    lapack_int            /* ldc */,
    lapack_complex_float *            /* work */,
    lapack_int            /* ldwork */
);
static PFNLAPACKE_clarfb_work _g_LAPACKE_clarfb_work = NULL;
lapack_int LAPACKE_clarfb_work(
    int            matrix_layout,
    char            side,
    char            trans,
    char            direct,
    char            storev,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    const lapack_complex_float *            v,
    lapack_int            ldv,
    const lapack_complex_float *            t,
    lapack_int            ldt,
    lapack_complex_float *            c,
    lapack_int            ldc,
    lapack_complex_float *            work,
    lapack_int            ldwork
)
{
    if(_g_LAPACKE_clarfb_work==NULL) {
        _g_LAPACKE_clarfb_work = rindow_load_libopenblas_func("LAPACKE_clarfb_work"); 
        if(_g_LAPACKE_clarfb_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clarfb_work(
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
        ldc,
        work,
        ldwork    
    );
}
