#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dhsein_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dhsein_work)( /* LAPACKE_dhsein_work */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* eigsrc */,
    char            /* initv */,
    lapack_logical *            /* select */,
    lapack_int            /* n */,
    const double *            /* h */,
    lapack_int            /* ldh */,
    double *            /* wr */,
    const double *            /* wi */,
    double *            /* vl */,
    lapack_int            /* ldvl */,
    double *            /* vr */,
    lapack_int            /* ldvr */,
    lapack_int            /* mm */,
    lapack_int *            /* m */,
    double *            /* work */,
    lapack_int *            /* ifaill */,
    lapack_int *            /* ifailr */
);
static PFNLAPACKE_dhsein_work _g_LAPACKE_dhsein_work = NULL;
lapack_int LAPACKE_dhsein_work(
    int            matrix_layout,
    char            job,
    char            eigsrc,
    char            initv,
    lapack_logical *            select,
    lapack_int            n,
    const double *            h,
    lapack_int            ldh,
    double *            wr,
    const double *            wi,
    double *            vl,
    lapack_int            ldvl,
    double *            vr,
    lapack_int            ldvr,
    lapack_int            mm,
    lapack_int *            m,
    double *            work,
    lapack_int *            ifaill,
    lapack_int *            ifailr
)
{
    if(_g_LAPACKE_dhsein_work==NULL) {
        _g_LAPACKE_dhsein_work = rindow_load_libopenblas_func("LAPACKE_dhsein_work"); 
        if(_g_LAPACKE_dhsein_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dhsein_work(
        matrix_layout,
        job,
        eigsrc,
        initv,
        select,
        n,
        h,
        ldh,
        wr,
        wi,
        vl,
        ldvl,
        vr,
        ldvr,
        mm,
        m,
        work,
        ifaill,
        ifailr    
    );
}
