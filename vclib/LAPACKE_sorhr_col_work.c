#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sorhr_col_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sorhr_col_work)( /* LAPACKE_sorhr_col_work */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* nb */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* t */,
    lapack_int            /* ldt */,
    float *            /* d */
);
static PFNLAPACKE_sorhr_col_work _g_LAPACKE_sorhr_col_work = NULL;
lapack_int LAPACKE_sorhr_col_work(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    lapack_int            nb,
    float *            a,
    lapack_int            lda,
    float *            t,
    lapack_int            ldt,
    float *            d
)
{
    if(_g_LAPACKE_sorhr_col_work==NULL) {
        _g_LAPACKE_sorhr_col_work = rindow_load_libopenblas_func("LAPACKE_sorhr_col_work"); 
        if(_g_LAPACKE_sorhr_col_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sorhr_col_work(
        matrix_layout,
        m,
        n,
        nb,
        a,
        lda,
        t,
        ldt,
        d    
    );
}
