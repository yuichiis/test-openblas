#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zpbstf_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zpbstf_work)( /* LAPACKE_zpbstf_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_int            /* kb */,
    lapack_complex_double *            /* bb */,
    lapack_int            /* ldbb */
);
static PFNLAPACKE_zpbstf_work _g_LAPACKE_zpbstf_work = NULL;
lapack_int LAPACKE_zpbstf_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    lapack_int            kb,
    lapack_complex_double *            bb,
    lapack_int            ldbb
)
{
    if(_g_LAPACKE_zpbstf_work==NULL) {
        _g_LAPACKE_zpbstf_work = rindow_load_libopenblas_func("LAPACKE_zpbstf_work"); 
        if(_g_LAPACKE_zpbstf_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zpbstf_work(
        matrix_layout,
        uplo,
        n,
        kb,
        bb,
        ldbb    
    );
}
