#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgebrd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgebrd_work)( /* LAPACKE_sgebrd_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* d */,
    float *            /* e */,
    float *            /* tauq */,
    float *            /* taup */,
    float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_sgebrd_work _g_LAPACKE_sgebrd_work = NULL;
lapack_int LAPACKE_sgebrd_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            d,
    float *            e,
    float *            tauq,
    float *            taup,
    float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_sgebrd_work==NULL) {
        _g_LAPACKE_sgebrd_work = rindow_load_libopenblas_func("LAPACKE_sgebrd_work"); 
        if(_g_LAPACKE_sgebrd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgebrd_work(
        matrix_layout,
        m,
        n,
        a,
        lda,
        d,
        e,
        tauq,
        taup,
        work,
        lwork    
    );
}
