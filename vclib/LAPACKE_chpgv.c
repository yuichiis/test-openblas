#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chpgv not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chpgv)( /* LAPACKE_chpgv */
    int            /* matrix_layout */,
    lapack_int            /* itype */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* ap */,
    lapack_complex_float *            /* bp */,
    float *            /* w */,
    lapack_complex_float *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_chpgv _g_LAPACKE_chpgv = NULL;
lapack_int LAPACKE_chpgv(
    int            matrix_layout,
    lapack_int            itype,
    char            jobz,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            ap,
    lapack_complex_float *            bp,
    float *            w,
    lapack_complex_float *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_chpgv==NULL) {
        _g_LAPACKE_chpgv = rindow_load_libopenblas_func("LAPACKE_chpgv"); 
        if(_g_LAPACKE_chpgv==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chpgv(
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
