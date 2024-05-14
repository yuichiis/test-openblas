#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chpgvx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chpgvx)( /* LAPACKE_chpgvx */
    int            /* matrix_layout */,
    lapack_int            /* itype */,
    char            /* jobz */,
    char            /* range */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_float *            /* ap */,
    lapack_complex_float *            /* bp */,
    float            /* vl */,
    float            /* vu */,
    lapack_int            /* il */,
    lapack_int            /* iu */,
    float            /* abstol */,
    lapack_int *            /* m */,
    float *            /* w */,
    lapack_complex_float *            /* z */,
    lapack_int            /* ldz */,
    lapack_int *            /* ifail */
);
static PFNLAPACKE_chpgvx _g_LAPACKE_chpgvx = NULL;
lapack_int LAPACKE_chpgvx(
    int            matrix_layout,
    lapack_int            itype,
    char            jobz,
    char            range,
    char            uplo,
    lapack_int            n,
    lapack_complex_float *            ap,
    lapack_complex_float *            bp,
    float            vl,
    float            vu,
    lapack_int            il,
    lapack_int            iu,
    float            abstol,
    lapack_int *            m,
    float *            w,
    lapack_complex_float *            z,
    lapack_int            ldz,
    lapack_int *            ifail
)
{
    if(_g_LAPACKE_chpgvx==NULL) {
        _g_LAPACKE_chpgvx = rindow_load_libopenblas_func("LAPACKE_chpgvx"); 
        if(_g_LAPACKE_chpgvx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chpgvx(
        matrix_layout,
        itype,
        jobz,
        range,
        uplo,
        n,
        ap,
        bp,
        vl,
        vu,
        il,
        iu,
        abstol,
        m,
        w,
        z,
        ldz,
        ifail    
    );
}
