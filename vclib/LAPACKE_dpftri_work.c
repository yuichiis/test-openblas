#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dpftri_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dpftri_work)( /* LAPACKE_dpftri_work */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* a */
);
static PFNLAPACKE_dpftri_work _g_LAPACKE_dpftri_work = NULL;
lapack_int LAPACKE_dpftri_work(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    double *            a
)
{
    if(_g_LAPACKE_dpftri_work==NULL) {
        _g_LAPACKE_dpftri_work = rindow_load_libopenblas_func("LAPACKE_dpftri_work"); 
        if(_g_LAPACKE_dpftri_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dpftri_work(
        matrix_layout,
        transr,
        uplo,
        n,
        a    
    );
}
