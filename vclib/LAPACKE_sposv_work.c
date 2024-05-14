#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sposv_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sposv_work)( /* LAPACKE_sposv_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* nrhs */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_sposv_work _g_LAPACKE_sposv_work = NULL;
lapack_int LAPACKE_sposv_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            nrhs,
    float *            a,
    lapack_int            lda,
    float *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_sposv_work==NULL) {
        _g_LAPACKE_sposv_work = rindow_load_libopenblas_func("LAPACKE_sposv_work"); 
        if(_g_LAPACKE_sposv_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sposv_work(
        matrix_layout,
        uplo,
        n,
        nrhs,
        a,
        lda,
        b,
        ldb    
    );
}
