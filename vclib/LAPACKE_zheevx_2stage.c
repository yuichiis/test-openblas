#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zheevx_2stage not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zheevx_2stage)( /* LAPACKE_zheevx_2stage */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* range */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
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
static PFNLAPACKE_zheevx_2stage _g_LAPACKE_zheevx_2stage = NULL;
lapack_int LAPACKE_zheevx_2stage(
    int            matrix_layout,
    char            jobz,
    char            range,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
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
    if(_g_LAPACKE_zheevx_2stage==NULL) {
        _g_LAPACKE_zheevx_2stage = rindow_load_libopenblas_func("LAPACKE_zheevx_2stage"); 
        if(_g_LAPACKE_zheevx_2stage==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zheevx_2stage(
        matrix_layout,
        jobz,
        range,
        uplo,
        n,
        a,
        lda,
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
