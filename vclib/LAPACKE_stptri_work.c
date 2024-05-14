#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_stptri_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_stptri_work)( /* LAPACKE_stptri_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    float *            /* ap */
);
static PFNLAPACKE_stptri_work _g_LAPACKE_stptri_work = NULL;
lapack_int LAPACKE_stptri_work(
    int            matrix_layout,
    char            uplo,
    char            diag,
    lapack_int            n,
    float *            ap
)
{
    if(_g_LAPACKE_stptri_work==NULL) {
        _g_LAPACKE_stptri_work = rindow_load_libopenblas_func("LAPACKE_stptri_work"); 
        if(_g_LAPACKE_stptri_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_stptri_work(
        matrix_layout,
        uplo,
        diag,
        n,
        ap    
    );
}
