#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sppequ_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sppequ_work)( /* LAPACKE_sppequ_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    lapack_int            /* n */,
    const float *            /* ap */,
    float *            /* s */,
    float *            /* scond */,
    float *            /* amax */
);
static PFNLAPACKE_sppequ_work _g_LAPACKE_sppequ_work = NULL;
lapack_int LAPACKE_sppequ_work(
    int            matrix_layout,
    char            uplo,
    lapack_int            n,
    const float *            ap,
    float *            s,
    float *            scond,
    float *            amax
)
{
    if(_g_LAPACKE_sppequ_work==NULL) {
        _g_LAPACKE_sppequ_work = rindow_load_libopenblas_func("LAPACKE_sppequ_work"); 
        if(_g_LAPACKE_sppequ_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sppequ_work(
        matrix_layout,
        uplo,
        n,
        ap,
        s,
        scond,
        amax    
    );
}
