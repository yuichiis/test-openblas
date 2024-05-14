#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sormbr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sormbr_work)( /* LAPACKE_sormbr_work */
    int            /* matrix_layout */,
    char            /* vect */,
    char            /* side */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* k */,
    const float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* tau */,
    float *            /* c */,
    lapack_int            /* ldc */,
    float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_sormbr_work _g_LAPACKE_sormbr_work = NULL;
lapack_int LAPACKE_sormbr_work(
    int            matrix_layout,
    char            vect,
    char            side,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    lapack_int            k,
    const float *            a,
    lapack_int            lda,
    const float *            tau,
    float *            c,
    lapack_int            ldc,
    float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_sormbr_work==NULL) {
        _g_LAPACKE_sormbr_work = rindow_load_libopenblas_func("LAPACKE_sormbr_work"); 
        if(_g_LAPACKE_sormbr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sormbr_work(
        matrix_layout,
        vect,
        side,
        trans,
        m,
        n,
        k,
        a,
        lda,
        tau,
        c,
        ldc,
        work,
        lwork    
    );
}
