#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cggesx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cggesx_work)( /* LAPACKE_cggesx_work */
    int            /* matrix_layout */,
    char            /* jobvsl */,
    char            /* jobvsr */,
    char            /* sort */,
    LAPACK_C_SELECT2            /* selctg */,
    char            /* sense */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_int *            /* sdim */,
    lapack_complex_float *            /* alpha */,
    lapack_complex_float *            /* beta */,
    lapack_complex_float *            /* vsl */,
    lapack_int            /* ldvsl */,
    lapack_complex_float *            /* vsr */,
    lapack_int            /* ldvsr */,
    float *            /* rconde */,
    float *            /* rcondv */,
    lapack_complex_float *            /* work */,
    lapack_int            /* lwork */,
    float *            /* rwork */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */,
    lapack_logical *            /* bwork */
);
static PFNLAPACKE_cggesx_work _g_LAPACKE_cggesx_work = NULL;
lapack_int LAPACKE_cggesx_work(
    int            matrix_layout,
    char            jobvsl,
    char            jobvsr,
    char            sort,
    LAPACK_C_SELECT2            selctg,
    char            sense,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_int *            sdim,
    lapack_complex_float *            alpha,
    lapack_complex_float *            beta,
    lapack_complex_float *            vsl,
    lapack_int            ldvsl,
    lapack_complex_float *            vsr,
    lapack_int            ldvsr,
    float *            rconde,
    float *            rcondv,
    lapack_complex_float *            work,
    lapack_int            lwork,
    float *            rwork,
    lapack_int *            iwork,
    lapack_int            liwork,
    lapack_logical *            bwork
)
{
    if(_g_LAPACKE_cggesx_work==NULL) {
        _g_LAPACKE_cggesx_work = rindow_load_libopenblas_func("LAPACKE_cggesx_work"); 
        if(_g_LAPACKE_cggesx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cggesx_work(
        matrix_layout,
        jobvsl,
        jobvsr,
        sort,
        selctg,
        sense,
        n,
        a,
        lda,
        b,
        ldb,
        sdim,
        alpha,
        beta,
        vsl,
        ldvsl,
        vsr,
        ldvsr,
        rconde,
        rcondv,
        work,
        lwork,
        rwork,
        iwork,
        liwork,
        bwork    
    );
}
