#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dspgv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dspgv)( /* LAPACKE_dspgv */
    int            /* matrix_layout */,
    lapack_int            /* itype */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    double *            /* ap */,
    double *            /* bp */,
    double *            /* w */,
    double *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_dspgv _g_LAPACKE_dspgv = NULL;
lapack_int LAPACKE_dspgv(
    int            matrix_layout,
    lapack_int            itype,
    char            jobz,
    char            uplo,
    lapack_int            n,
    double *            ap,
    double *            bp,
    double *            w,
    double *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_dspgv==NULL) {
        _g_LAPACKE_dspgv = rindow_load_libopenblas_func("LAPACKE_dspgv"); 
        if(_g_LAPACKE_dspgv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dspgv(
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
