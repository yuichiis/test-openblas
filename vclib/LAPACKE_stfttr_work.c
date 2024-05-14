#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_stfttr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_stfttr_work)( /* LAPACKE_stfttr_work */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    const float *            /* arf */,
    float *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_stfttr_work _g_LAPACKE_stfttr_work = NULL;
lapack_int LAPACKE_stfttr_work(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    const float *            arf,
    float *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_stfttr_work==NULL) {
        _g_LAPACKE_stfttr_work = rindow_load_libopenblas_func("LAPACKE_stfttr_work"); 
        if(_g_LAPACKE_stfttr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_stfttr_work(
        matrix_layout,
        transr,
        uplo,
        n,
        arf,
        a,
        lda    
    );
}
