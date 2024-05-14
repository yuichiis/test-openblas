#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctgsyl_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctgsyl_work)( /* LAPACKE_ctgsyl_work */
    int            /* matrix_layout */,
    char            /* trans */,
    lapack_int            /* ijob */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* c */,
    lapack_int            /* ldc */,
    const lapack_complex_float *            /* d */,
    lapack_int            /* ldd */,
    const lapack_complex_float *            /* e */,
    lapack_int            /* lde */,
    lapack_complex_float *            /* f */,
    lapack_int            /* ldf */,
    float *            /* scale */,
    float *            /* dif */,
    lapack_complex_float *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_ctgsyl_work _g_LAPACKE_ctgsyl_work = NULL;
lapack_int LAPACKE_ctgsyl_work(
    int            matrix_layout,
    char            trans,
    lapack_int            ijob,
    lapack_int            m,
    lapack_int            n,
    const lapack_complex_float *            a,
    lapack_int            lda,
    const lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            c,
    lapack_int            ldc,
    const lapack_complex_float *            d,
    lapack_int            ldd,
    const lapack_complex_float *            e,
    lapack_int            lde,
    lapack_complex_float *            f,
    lapack_int            ldf,
    float *            scale,
    float *            dif,
    lapack_complex_float *            work,
    lapack_int            lwork,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_ctgsyl_work==NULL) {
        _g_LAPACKE_ctgsyl_work = rindow_load_libopenblas_func("LAPACKE_ctgsyl_work"); 
        if(_g_LAPACKE_ctgsyl_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctgsyl_work(
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
