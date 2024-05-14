#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_stpmqrt_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_stpmqrt_work)( /* LAPACKE_stpmqrt_work */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    lapack_int            /* l */,
    lapack_int            /* nb */,
    const float *            /* v */,
    lapack_int            /* ldv */,
    const float *            /* t */,
    lapack_int            /* ldt */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* work */
);
static PFNLAPACKE_stpmqrt_work _g_LAPACKE_stpmqrt_work = NULL;
lapack_int LAPACKE_stpmqrt_work(
    int            matrix_layout,
    char            side,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    lapack_int            l,
    lapack_int            nb,
    const float *            v,
    lapack_int            ldv,
    const float *            t,
    lapack_int            ldt,
    float *            a,
    lapack_int            lda,
    float *            b,
    lapack_int            ldb,
    float *            work
)
{
    if(_g_LAPACKE_stpmqrt_work==NULL) {
        _g_LAPACKE_stpmqrt_work = rindow_load_libopenblas_func("LAPACKE_stpmqrt_work"); 
        if(_g_LAPACKE_stpmqrt_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_stpmqrt_work(
        matrix_layout,
        side,
        trans,
        m,
        n,
        k,
        l,
        nb,
        v,
        ldv,
        t,
        ldt,
        a,
        lda,
        b,
        ldb,
        work    
    );
}
