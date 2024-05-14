#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhetrd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhetrd_work)( /* LAPACKE_zhetrd_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    double *            /* d */,
    double *            /* e */,
    lapack_complex_double *            /* tau */,
    lapack_complex_double *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_zhetrd_work _g_LAPACKE_zhetrd_work = NULL;
lapack_int LAPACKE_zhetrd_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    double *            d,
    double *            e,
    lapack_complex_double *            tau,
    lapack_complex_double *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_zhetrd_work==NULL) {
        _g_LAPACKE_zhetrd_work = rindow_load_libopenblas_func("LAPACKE_zhetrd_work"); 
        if(_g_LAPACKE_zhetrd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhetrd_work(
        matrix_layout,
        uplo,
        n,
        a,
        lda,
        d,
        e,
        tau,
        work,
        lwork    
    );
}
