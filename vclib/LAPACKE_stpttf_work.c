#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_stpttf_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_stpttf_work)( /* LAPACKE_stpttf_work */
    int            /* matrix_layout */,
    char            /* transr */,
    char            /* uplo */,
    lapack_int            /* n */,
    const float *            /* ap */,
    float *            /* arf */
);
static PFNLAPACKE_stpttf_work _g_LAPACKE_stpttf_work = NULL;
lapack_int LAPACKE_stpttf_work(
    int            matrix_layout,
    char            transr,
    char            uplo,
    lapack_int            n,
    const float *            ap,
    float *            arf
)
{
    if(_g_LAPACKE_stpttf_work==NULL) {
        _g_LAPACKE_stpttf_work = rindow_load_libopenblas_func("LAPACKE_stpttf_work"); 
        if(_g_LAPACKE_stpttf_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_stpttf_work(
        matrix_layout,
        transr,
        uplo,
        n,
        ap,
        arf    
    );
}
