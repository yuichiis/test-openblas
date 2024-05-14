#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztgsyl_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztgsyl_work)( /* LAPACKE_ztgsyl_work */
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
    double *            /* dif */,
    lapack_complex_double *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_ztgsyl_work _g_LAPACKE_ztgsyl_work = NULL;
lapack_int LAPACKE_ztgsyl_work(
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
    double *            dif,
    lapack_complex_double *            work,
    lapack_int            lwork,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_ztgsyl_work==NULL) {
        _g_LAPACKE_ztgsyl_work = rindow_load_libopenblas_func("LAPACKE_ztgsyl_work"); 
        if(_g_LAPACKE_ztgsyl_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztgsyl_work(
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
        dif,
        work,
        lwork,
        iwork    
    );
}
