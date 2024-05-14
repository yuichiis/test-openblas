#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlarfb_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zlarfb_work)( /* LAPACKE_zlarfb_work */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* trans */,
    char            /* direct */,
    char            /* storev */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const lapack_complex_double *            /* v */,
    lapack_int            /* ldv */,
    const lapack_complex_double *            /* t */,
    lapack_int            /* ldt */,
    lapack_complex_double *            /* c */,
    lapack_int            /* ldc */,
    lapack_complex_double *            /* work */,
    lapack_int            /* ldwork */
);
static PFNLAPACKE_zlarfb_work _g_LAPACKE_zlarfb_work = NULL;
lapack_int LAPACKE_zlarfb_work(
    int            matrix_layout,
    char            side,
    char            trans,
    char            direct,
    char            storev,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    const lapack_complex_double *            v,
    lapack_int            ldv,
    const lapack_complex_double *            t,
    lapack_int            ldt,
    lapack_complex_double *            c,
    lapack_int            ldc,
    lapack_complex_double *            work,
    lapack_int            ldwork
)
{
    if(_g_LAPACKE_zlarfb_work==NULL) {
        _g_LAPACKE_zlarfb_work = rindow_load_libopenblas_func("LAPACKE_zlarfb_work"); 
        if(_g_LAPACKE_zlarfb_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlarfb_work(
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
