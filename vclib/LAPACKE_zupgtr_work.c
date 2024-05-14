#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zupgtr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zupgtr_work)( /* LAPACKE_zupgtr_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* ap */,
    const lapack_complex_double *            /* tau */,
    lapack_complex_double *            /* q */,
    lapack_int            /* ldq */,
    lapack_complex_double *            /* work */
);
static PFNLAPACKE_zupgtr_work _g_LAPACKE_zupgtr_work = NULL;
lapack_int LAPACKE_zupgtr_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const lapack_complex_double *            ap,
    const lapack_complex_double *            tau,
    lapack_complex_double *            q,
    lapack_int            ldq,
    lapack_complex_double *            work
)
{
    if(_g_LAPACKE_zupgtr_work==NULL) {
        _g_LAPACKE_zupgtr_work = rindow_load_libopenblas_func("LAPACKE_zupgtr_work"); 
        if(_g_LAPACKE_zupgtr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zupgtr_work(
        matrix_layout,
        uplo,
        n,
        ap,
        tau,
        q,
        ldq,
        work    
    );
}
