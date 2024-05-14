#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_stbcon_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_stbcon_work)( /* LAPACKE_stbcon_work */
    int            /* matrix_layout */,
    char            /* norm */,
    char            /* uplo */,
    char            /* diag */,
    lapack_int            /* n */,
    lapack_int            /* kd */,
    const float *            /* ab */,
    lapack_int            /* ldab */,
    float *            /* rcond */,
    float *            /* work */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_stbcon_work _g_LAPACKE_stbcon_work = NULL;
lapack_int LAPACKE_stbcon_work(
    int            matrix_layout,
    char            norm,
    char            uplo,
    char            diag,
    lapack_int            n,
    lapack_int            kd,
    const float *            ab,
    lapack_int            ldab,
    float *            rcond,
    float *            work,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_stbcon_work==NULL) {
        _g_LAPACKE_stbcon_work = rindow_load_libopenblas_func("LAPACKE_stbcon_work"); 
        if(_g_LAPACKE_stbcon_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_stbcon_work(
        matrix_layout,
        norm,
        uplo,
        diag,
        n,
        kd,
        ab,
        ldab,
        rcond,
        work,
        iwork    
    );
}
