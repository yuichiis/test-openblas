#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztgsyl not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztgsyl)( /* LAPACKE_ztgsyl */
    int            /* matrix_layout */,
    char            /* trans */,
    lapack_int            /* ijob */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_double *            /* c */,
    lapack_int            /* ldc */,
    const lapack_complex_double *            /* d */,
    lapack_int            /* ldd */,
    const lapack_complex_double *            /* e */,
    lapack_int            /* lde */,
    lapack_complex_double *            /* f */,
    lapack_int            /* ldf */,
    double *            /* scale */,
    double *            /* dif */
);
static PFNLAPACKE_ztgsyl _g_LAPACKE_ztgsyl = NULL;
lapack_int LAPACKE_ztgsyl(
    int            matrix_layout,
    char            trans,
    lapack_int            ijob,
    lapack_int            m,
    lapack_int            n,
    const lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_complex_double *            c,
    lapack_int            ldc,
    const lapack_complex_double *            d,
    lapack_int            ldd,
    const lapack_complex_double *            e,
    lapack_int            lde,
    lapack_complex_double *            f,
    lapack_int            ldf,
    double *            scale,
    double *            dif
)
{
    if(_g_LAPACKE_ztgsyl==NULL) {
        _g_LAPACKE_ztgsyl = rindow_load_libopenblas_func("LAPACKE_ztgsyl"); 
        if(_g_LAPACKE_ztgsyl==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztgsyl(
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
