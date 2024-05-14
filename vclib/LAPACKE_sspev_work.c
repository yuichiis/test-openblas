#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sspev_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sspev_work)( /* LAPACKE_sspev_work */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* ap */,
    float *            /* w */,
    float *            /* z */,
    lapack_int            /* ldz */,
    float *            /* work */
);
static PFNLAPACKE_sspev_work _g_LAPACKE_sspev_work = NULL;
lapack_int LAPACKE_sspev_work(
    int            matrix_layout,
    char            jobz,
    char            uplo,
    lapack_int            n,
    float *            ap,
    float *            w,
    float *            z,
    lapack_int            ldz,
    float *            work
)
{
    if(_g_LAPACKE_sspev_work==NULL) {
        _g_LAPACKE_sspev_work = rindow_load_libopenblas_func("LAPACKE_sspev_work"); 
        if(_g_LAPACKE_sspev_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sspev_work(
        matrix_layout,
        jobz,
        uplo,
        n,
        ap,
        w,
        z,
        ldz,
        work    
    );
}
