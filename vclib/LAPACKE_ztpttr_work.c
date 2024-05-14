#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztpttr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztpttr_work)( /* LAPACKE_ztpttr_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* ap */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_ztpttr_work _g_LAPACKE_ztpttr_work = NULL;
lapack_int LAPACKE_ztpttr_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const lapack_complex_double *            ap,
    lapack_complex_double *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_ztpttr_work==NULL) {
        _g_LAPACKE_ztpttr_work = rindow_load_libopenblas_func("LAPACKE_ztpttr_work"); 
        if(_g_LAPACKE_ztpttr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztpttr_work(
        matrix_layout,
        uplo,
        n,
        ap,
        a,
        lda    
    );
}
