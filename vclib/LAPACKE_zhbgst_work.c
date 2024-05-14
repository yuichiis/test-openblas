#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhbgst_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhbgst_work)( /* LAPACKE_zhbgst_work */
    int            /* matrix_layout */,
    char            /* vect */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* ka */,
    lapack_int            /* kb */,
    lapack_complex_double *            /* ab */,
    lapack_int            /* ldab */,
    const lapack_complex_double *            /* bb */,
    lapack_int            /* ldbb */,
    lapack_complex_double *            /* x */,
    lapack_int            /* ldx */,
    lapack_complex_double *            /* work */,
    double *            /* rwork */
);
static PFNLAPACKE_zhbgst_work _g_LAPACKE_zhbgst_work = NULL;
lapack_int LAPACKE_zhbgst_work(
    int            matrix_layout,
    char            vect,
    char            uplo,
    lapack_int            n,
    lapack_int            ka,
    lapack_int            kb,
    lapack_complex_double *            ab,
    lapack_int            ldab,
    const lapack_complex_double *            bb,
    lapack_int            ldbb,
    lapack_complex_double *            x,
    lapack_int            ldx,
    lapack_complex_double *            work,
    double *            rwork
)
{
    if(_g_LAPACKE_zhbgst_work==NULL) {
        _g_LAPACKE_zhbgst_work = rindow_load_libopenblas_func("LAPACKE_zhbgst_work"); 
        if(_g_LAPACKE_zhbgst_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhbgst_work(
        matrix_layout,
        vect,
        uplo,
        n,
        ka,
        kb,
        ab,
        ldab,
        bb,
        ldbb,
        x,
        ldx,
        work,
        rwork    
    );
}
