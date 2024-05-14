#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztgsna_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztgsna_work)( /* LAPACKE_ztgsna_work */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* howmny */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    const lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    const lapack_complex_double *            /* vl */,
    lapack_int            /* ldvl */,
    const lapack_complex_double *            /* vr */,
    lapack_int            /* ldvr */,
    double *            /* s */,
    double *            /* dif */,
    lapack_int            /* mm */,
    lapack_int *            /* m */,
    lapack_complex_double *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_ztgsna_work _g_LAPACKE_ztgsna_work = NULL;
lapack_int LAPACKE_ztgsna_work(
    int            matrix_layout,
    char            job,
    char            howmny,
    const lapack_logical *            select,
    lapack_int            n,
    const lapack_complex_double *            a,
    lapack_int            lda,
    const lapack_complex_double *            b,
    lapack_int            ldb,
    const lapack_complex_double *            vl,
    lapack_int            ldvl,
    const lapack_complex_double *            vr,
    lapack_int            ldvr,
    double *            s,
    double *            dif,
    lapack_int            mm,
    lapack_int *            m,
    lapack_complex_double *            work,
    lapack_int            lwork,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_ztgsna_work==NULL) {
        _g_LAPACKE_ztgsna_work = rindow_load_libopenblas_func("LAPACKE_ztgsna_work"); 
        if(_g_LAPACKE_ztgsna_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztgsna_work(
        matrix_layout,
        job,
        howmny,
        select,
        n,
        a,
        lda,
        b,
        ldb,
        vl,
        ldvl,
        vr,
        ldvr,
        s,
        dif,
        mm,
        m,
        work,
        lwork,
        iwork    
    );
}
