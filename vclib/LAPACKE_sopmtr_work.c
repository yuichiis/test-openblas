#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sopmtr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sopmtr_work)( /* LAPACKE_sopmtr_work */
    int            /* matrix_layout */,
    char            /* side */,
    char            /* uplo */,
    char            /* trans */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const float *            /* ap */,
    const float *            /* tau */,
    float *            /* c */,
    lapack_int            /* ldc */,
    float *            /* work */
);
static PFNLAPACKE_sopmtr_work _g_LAPACKE_sopmtr_work = NULL;
lapack_int LAPACKE_sopmtr_work(
    int            matrix_layout,
    char            side,
    char            uplo,
    char            trans,
    lapack_int            m,
    lapack_int            n,
    const float *            ap,
    const float *            tau,
    float *            c,
    lapack_int            ldc,
    float *            work
)
{
    if(_g_LAPACKE_sopmtr_work==NULL) {
        _g_LAPACKE_sopmtr_work = rindow_load_libopenblas_func("LAPACKE_sopmtr_work"); 
        if(_g_LAPACKE_sopmtr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sopmtr_work(
        matrix_layout,
        side,
        uplo,
        trans,
        m,
        n,
        ap,
        tau,
        c,
        ldc,
        work    
    );
}
