#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chpgvd not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chpgvd)( /* LAPACKE_chpgvd */
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
static PFNLAPACKE_chpgvd _g_LAPACKE_chpgvd = NULL;
lapack_int LAPACKE_chpgvd(
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
    if(_g_LAPACKE_chpgvd==NULL) {
        _g_LAPACKE_chpgvd = rindow_load_libopenblas_func("LAPACKE_chpgvd"); 
        if(_g_LAPACKE_chpgvd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chpgvd(
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
