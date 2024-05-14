#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cpftri_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cpftri_work)( /* LAPACKE_cpftri_work */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */
);
static PFNLAPACKE_cpftri_work _g_LAPACKE_cpftri_work = NULL;
lapack_int LAPACKE_cpftri_work(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            a
)
{
    if(_g_LAPACKE_cpftri_work==NULL) {
        _g_LAPACKE_cpftri_work = rindow_load_libopenblas_func("LAPACKE_cpftri_work"); 
        if(_g_LAPACKE_cpftri_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cpftri_work(
        matrix_layout,
        transr,
        uplo,
        n,
        a    
    );
}
