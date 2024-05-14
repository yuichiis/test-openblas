#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtgsyl not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtgsyl)( /* LAPACKE_dtgsyl */
    int            /* matrix_layout */,
    char            /* trans */,
    lapack_int            /* ijob */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const double *            /* a */,
    lapack_int            /* lda */,
    const double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* c */,
    lapack_int            /* ldc */,
    const double *            /* d */,
    lapack_int            /* ldd */,
    const double *            /* e */,
    lapack_int            /* lde */,
    double *            /* f */,
    lapack_int            /* ldf */,
    double *            /* scale */,
    double *            /* dif */
);
static PFNLAPACKE_dtgsyl _g_LAPACKE_dtgsyl = NULL;
lapack_int LAPACKE_dtgsyl(
    int            matrix_layout,
    char            trans,
    lapack_int            ijob,
    lapack_int            m,
    lapack_int            n,
    const double *            a,
    lapack_int            lda,
    const double *            b,
    lapack_int            ldb,
    double *            c,
    lapack_int            ldc,
    const double *            d,
    lapack_int            ldd,
    const double *            e,
    lapack_int            lde,
    double *            f,
    lapack_int            ldf,
    double *            scale,
    double *            dif
)
{
    if(_g_LAPACKE_dtgsyl==NULL) {
        _g_LAPACKE_dtgsyl = rindow_load_libopenblas_func("LAPACKE_dtgsyl"); 
        if(_g_LAPACKE_dtgsyl==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtgsyl(
        matrix_layout,
        trans,
        ijob,
        m,
        n,
        a,
        lda,
        b,
        ldb,
        c,
        ldc,
        d,
        ldd,
        e,
        lde,
        f,
        ldf,
        scale,
        dif    
    );
}
