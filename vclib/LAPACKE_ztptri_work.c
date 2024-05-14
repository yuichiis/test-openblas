#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztptri_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztptri_work)( /* LAPACKE_ztptri_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    lapack_complex_double *            /* ap */
);
static PFNLAPACKE_ztptri_work _g_LAPACKE_ztptri_work = NULL;
lapack_int LAPACKE_ztptri_work(
    int            matrix_layout,
    char            uplo,
    char            diag,
    lapack_int            n,
    lapack_complex_double *            ap
)
{
    if(_g_LAPACKE_ztptri_work==NULL) {
        _g_LAPACKE_ztptri_work = rindow_load_libopenblas_func("LAPACKE_ztptri_work"); 
        if(_g_LAPACKE_ztptri_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztptri_work(
        matrix_layout,
        uplo,
        diag,
        n,
        ap    
    );
}
