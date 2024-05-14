#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhpev_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhpev_work)( /* LAPACKE_zhpev_work */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* ap */,
    double *            /* w */,
    lapack_complex_double *            /* z */,
    lapack_int            /* ldz */,
    lapack_complex_double *            /* work */,
    double *            /* rwork */
);
static PFNLAPACKE_zhpev_work _g_LAPACKE_zhpev_work = NULL;
lapack_int LAPACKE_zhpev_work(
    int            matrix_layout,
    char            jobz,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            ap,
    double *            w,
    lapack_complex_double *            z,
    lapack_int            ldz,
    lapack_complex_double *            work,
    double *            rwork
)
{
    if(_g_LAPACKE_zhpev_work==NULL) {
        _g_LAPACKE_zhpev_work = rindow_load_libopenblas_func("LAPACKE_zhpev_work"); 
        if(_g_LAPACKE_zhpev_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhpev_work(
        matrix_layout,
        jobz,
        uplo,
        n,
        ap,
        w,
        z,
        ldz,
        work,
        rwork    
    );
}
