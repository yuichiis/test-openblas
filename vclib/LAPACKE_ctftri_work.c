#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctftri_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctftri_work)( /* LAPACKE_ctftri_work */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */
);
static PFNLAPACKE_ctftri_work _g_LAPACKE_ctftri_work = NULL;
lapack_int LAPACKE_ctftri_work(
    int            matrix_layout,
    char            transr,
    char            uplo,
    char            diag,
    lapack_int            n,
    lapack_complex_float *            a
)
{
    if(_g_LAPACKE_ctftri_work==NULL) {
        _g_LAPACKE_ctftri_work = rindow_load_libopenblas_func("LAPACKE_ctftri_work"); 
        if(_g_LAPACKE_ctftri_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctftri_work(
        matrix_layout,
        transr,
        uplo,
        diag,
        n,
        a    
    );
}
