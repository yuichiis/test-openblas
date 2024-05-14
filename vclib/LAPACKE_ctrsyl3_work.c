#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctrsyl3_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctrsyl3_work)( /* LAPACKE_ctrsyl3_work */
    int            /* matrix_layout */,
    char            /* trana */,
    char            /* tranb */,
    lapack_int            /* isgn */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* c */,
    lapack_int            /* ldc */,
    float *            /* scale */,
    float *            /* swork */,
    lapack_int            /* ldswork */
);
static PFNLAPACKE_ctrsyl3_work _g_LAPACKE_ctrsyl3_work = NULL;
lapack_int LAPACKE_ctrsyl3_work(
    int            matrix_layout,
    char            trana,
    char            tranb,
    lapack_int            isgn,
    lapack_int            m,
    lapack_int            n,
    const lapack_complex_float *            a,
    lapack_int            lda,
    const lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            c,
    lapack_int            ldc,
    float *            scale,
    float *            swork,
    lapack_int            ldswork
)
{
    if(_g_LAPACKE_ctrsyl3_work==NULL) {
        _g_LAPACKE_ctrsyl3_work = rindow_load_libopenblas_func("LAPACKE_ctrsyl3_work"); 
        if(_g_LAPACKE_ctrsyl3_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctrsyl3_work(
        matrix_layout,
        trana,
        tranb,
        isgn,
        m,
        n,
        a,
        lda,
        b,
        ldb,
        c,
        ldc,
        scale,
        swork,
        ldswork    
    );
}
