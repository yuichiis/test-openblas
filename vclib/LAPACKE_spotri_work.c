#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_spotri_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_spotri_work)( /* LAPACKE_spotri_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_spotri_work _g_LAPACKE_spotri_work = NULL;
lapack_int LAPACKE_spotri_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    float *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_spotri_work==NULL) {
        _g_LAPACKE_spotri_work = rindow_load_libopenblas_func("LAPACKE_spotri_work"); 
        if(_g_LAPACKE_spotri_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_spotri_work(
        matrix_layout,
        uplo,
        n,
        a,
        lda    
    );
}
