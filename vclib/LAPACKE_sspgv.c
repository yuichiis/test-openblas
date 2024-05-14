#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sspgv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sspgv)( /* LAPACKE_sspgv */
    int            /* matrix_layout */,
    lapack_int            /* itype */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    float *            /* ap */,
    float *            /* bp */,
    float *            /* w */,
    float *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_sspgv _g_LAPACKE_sspgv = NULL;
lapack_int LAPACKE_sspgv(
    int            matrix_layout,
    lapack_int            itype,
    char            jobz,
    char            uplo,
    lapack_int            n,
    float *            ap,
    float *            bp,
    float *            w,
    float *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_sspgv==NULL) {
        _g_LAPACKE_sspgv = rindow_load_libopenblas_func("LAPACKE_sspgv"); 
        if(_g_LAPACKE_sspgv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sspgv(
        matrix_layout,
        itype,
        jobz,
        uplo,
        n,
        ap,
        bp,
        w,
        z,
        ldz    
    );
}
