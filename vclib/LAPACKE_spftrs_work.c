#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spftrs_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spftrs_work)( /* LAPACKE_spftrs_work */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    const float *            /* a */,
    float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_spftrs_work _g_LAPACKE_spftrs_work = NULL;
lapack_int LAPACKE_spftrs_work(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    const float *            a,
    float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_spftrs_work==NULL) {
        _g_LAPACKE_spftrs_work = rindow_load_libopenblas_func("LAPACKE_spftrs_work"); 
        if(_g_LAPACKE_spftrs_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spftrs_work(
        matrix_layout,
        transr,
        uplo,
        n,
        nrhs,
        a,
        b,
        ldb    
    );
}
