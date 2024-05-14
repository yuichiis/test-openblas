#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sppsv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sppsv)( /* LAPACKE_sppsv */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    float *            /* ap */,
    float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_sppsv _g_LAPACKE_sppsv = NULL;
lapack_int LAPACKE_sppsv(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    float *            ap,
    float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_sppsv==NULL) {
        _g_LAPACKE_sppsv = rindow_load_libopenblas_func("LAPACKE_sppsv"); 
        if(_g_LAPACKE_sppsv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sppsv(
        matrix_layout,
        uplo,
        n,
        nrhs,
        ap,
        b,
        ldb    
    );
}
