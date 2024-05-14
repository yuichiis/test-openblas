#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dhsein not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dhsein)( /* LAPACKE_dhsein */
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
    lapack_int *            /* ifaill */,
    lapack_int *            /* ifailr */
);
static PFNLAPACKE_dhsein _g_LAPACKE_dhsein = NULL;
lapack_int LAPACKE_dhsein(
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
    lapack_int *            ifaill,
    lapack_int *            ifailr
)
{
    if(_g_LAPACKE_dhsein==NULL) {
        _g_LAPACKE_dhsein = rindow_load_libopenblas_func("LAPACKE_dhsein"); 
        if(_g_LAPACKE_dhsein==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dhsein(
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
        ifaill,
        ifailr    
    );
}
