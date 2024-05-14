#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhbtrd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhbtrd_work)( /* LAPACKE_zhbtrd_work */
    int            /* matrix_layout */,
    char            /* vect */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    lapack_complex_double *            /* ab */,
    lapack_int            /* ldab */,
    double *            /* d */,
    double *            /* e */,
    lapack_complex_double *            /* q */,
    lapack_int            /* ldq */,
    lapack_complex_double *            /* work */
);
static PFNLAPACKE_zhbtrd_work _g_LAPACKE_zhbtrd_work = NULL;
lapack_int LAPACKE_zhbtrd_work(
    int            matrix_layout,
    char            vect,
    char            uplo,
    lapack_int            n,
    lapack_int            kd,
    lapack_complex_double *            ab,
    lapack_int            ldab,
    double *            d,
    double *            e,
    lapack_complex_double *            q,
    lapack_int            ldq,
    lapack_complex_double *            work
)
{
    if(_g_LAPACKE_zhbtrd_work==NULL) {
        _g_LAPACKE_zhbtrd_work = rindow_load_libopenblas_func("LAPACKE_zhbtrd_work"); 
        if(_g_LAPACKE_zhbtrd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhbtrd_work(
        matrix_layout,
        vect,
        uplo,
        n,
        kd,
        ab,
        ldab,
        d,
        e,
        q,
        ldq,
        work    
    );
}
