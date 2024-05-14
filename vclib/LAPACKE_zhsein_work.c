#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhsein_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhsein_work)( /* LAPACKE_zhsein_work */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* eigsrc */,
    char            /* initv */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    const lapack_complex_double *            /* h */,
    lapack_int            /* ldh */,
    lapack_complex_double *            /* w */,
    lapack_complex_double *            /* vl */,
    lapack_int            /* ldvl */,
    lapack_complex_double *            /* vr */,
    lapack_int            /* ldvr */,
    lapack_int            /* mm */,
    lapack_int *            /* m */,
    lapack_complex_double *            /* work */,
    double *            /* rwork */,
    lapack_int *            /* ifaill */,
    lapack_int *            /* ifailr */
);
static PFNLAPACKE_zhsein_work _g_LAPACKE_zhsein_work = NULL;
lapack_int LAPACKE_zhsein_work(
    int            matrix_layout,
    char            job,
    char            eigsrc,
    char            initv,
    const lapack_logical *            select,
    lapack_int            n,
    const lapack_complex_double *            h,
    lapack_int            ldh,
    lapack_complex_double *            w,
    lapack_complex_double *            vl,
    lapack_int            ldvl,
    lapack_complex_double *            vr,
    lapack_int            ldvr,
    lapack_int            mm,
    lapack_int *            m,
    lapack_complex_double *            work,
    double *            rwork,
    lapack_int *            ifaill,
    lapack_int *            ifailr
)
{
    if(_g_LAPACKE_zhsein_work==NULL) {
        _g_LAPACKE_zhsein_work = rindow_load_libopenblas_func("LAPACKE_zhsein_work"); 
        if(_g_LAPACKE_zhsein_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhsein_work(
        matrix_layout,
        job,
        eigsrc,
        initv,
        select,
        n,
        h,
        ldh,
        w,
        vl,
        ldvl,
        vr,
        ldvr,
        mm,
        m,
        work,
        rwork,
        ifaill,
        ifailr    
    );
}
