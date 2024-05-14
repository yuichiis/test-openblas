#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dpotri_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dpotri_work)( /* LAPACKE_dpotri_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_dpotri_work _g_LAPACKE_dpotri_work = NULL;
lapack_int LAPACKE_dpotri_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    double *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_dpotri_work==NULL) {
        _g_LAPACKE_dpotri_work = rindow_load_libopenblas_func("LAPACKE_dpotri_work"); 
        if(_g_LAPACKE_dpotri_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dpotri_work(
        matrix_layout,
        uplo,
        n,
        a,
        lda    
    );
}
