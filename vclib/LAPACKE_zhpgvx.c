#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhpgvx not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhpgvx)( /* LAPACKE_zhpgvx */
    int            /* matrix_layout */,
    lapack_int            /* itype */,
    char            /* jobz */,
    char            /* range */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* ap */,
    lapack_complex_double *            /* bp */,
    double            /* vl */,
    double            /* vu */,
    lapack_int            /* il */,
    lapack_int            /* iu */,
    double            /* abstol */,
    lapack_int *            /* m */,
    double *            /* w */,
    lapack_complex_double *            /* z */,
    lapack_int            /* ldz */,
    lapack_int *            /* ifail */
);
static PFNLAPACKE_zhpgvx _g_LAPACKE_zhpgvx = NULL;
lapack_int LAPACKE_zhpgvx(
    int            matrix_layout,
    lapack_int            itype,
    char            jobz,
    char            range,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            ap,
    lapack_complex_double *            bp,
    double            vl,
    double            vu,
    lapack_int            il,
    lapack_int            iu,
    double            abstol,
    lapack_int *            m,
    double *            w,
    lapack_complex_double *            z,
    lapack_int            ldz,
    lapack_int *            ifail
)
{
    if(_g_LAPACKE_zhpgvx==NULL) {
        _g_LAPACKE_zhpgvx = rindow_load_libopenblas_func("LAPACKE_zhpgvx"); 
        if(_g_LAPACKE_zhpgvx==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhpgvx(
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
