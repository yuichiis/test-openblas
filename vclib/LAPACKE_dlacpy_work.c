#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlacpy_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlacpy_work)( /* LAPACKE_dlacpy_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const double *            /* a */,
    lapack_int            /* lda */,
    double *            /* b */,
    lapack_int            /* ldb */
);
static PFNLAPACKE_dlacpy_work _g_LAPACKE_dlacpy_work = NULL;
lapack_int LAPACKE_dlacpy_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            m,
    lapack_int            n,
    const double *            a,
    lapack_int            lda,
    double *            b,
    lapack_int            ldb
)
{
    if(_g_LAPACKE_dlacpy_work==NULL) {
        _g_LAPACKE_dlacpy_work = rindow_load_libopenblas_func("LAPACKE_dlacpy_work"); 
        if(_g_LAPACKE_dlacpy_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlacpy_work(
        matrix_layout,
        uplo,
        m,
        n,
        a,
        lda,
        b,
        ldb    
    );
}
