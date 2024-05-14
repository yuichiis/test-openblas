#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctfttr_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctfttr_work)( /* LAPACKE_ctfttr_work */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* arf */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */
);
static PFNLAPACKE_ctfttr_work _g_LAPACKE_ctfttr_work = NULL;
lapack_int LAPACKE_ctfttr_work(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    const lapack_complex_float *            arf,
    lapack_complex_float *            a,
    lapack_int            lda
)
{
    if(_g_LAPACKE_ctfttr_work==NULL) {
        _g_LAPACKE_ctfttr_work = rindow_load_libopenblas_func("LAPACKE_ctfttr_work"); 
        if(_g_LAPACKE_ctfttr_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctfttr_work(
        matrix_layout,
        transr,
        uplo,
        n,
        arf,
        a,
        lda    
    );
}
