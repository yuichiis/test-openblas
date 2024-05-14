#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhegv_2stage not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhegv_2stage)( /* LAPACKE_zhegv_2stage */
    int            /* matrix_layout */,
    lapack_int            /* itype */,
    char            /* jobz */,
    char            /* uplo */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* w */
);
static PFNLAPACKE_zhegv_2stage _g_LAPACKE_zhegv_2stage = NULL;
lapack_int LAPACKE_zhegv_2stage(
    int            matrix_layout,
    lapack_int            itype,
    char            jobz,
    char            uplo,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            b,
    lapack_int            ldb,
    double *            w
)
{
    if(_g_LAPACKE_zhegv_2stage==NULL) {
        _g_LAPACKE_zhegv_2stage = rindow_load_libopenblas_func("LAPACKE_zhegv_2stage"); 
        if(_g_LAPACKE_zhegv_2stage==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhegv_2stage(
        matrix_layout,
        itype,
        jobz,
        uplo,
        n,
        a,
        lda,
        b,
        ldb,
        w    
    );
}
