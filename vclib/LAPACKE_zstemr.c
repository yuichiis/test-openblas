#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zstemr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zstemr)( /* LAPACKE_zstemr */
    int            /* matrix_layout */,
    char            /* jobz */,
    char            /* range */,
    lapack_int            /* n */,
    double *            /* d */,
    double *            /* e */,
    double            /* vl */,
    double            /* vu */,
    lapack_int            /* il */,
    lapack_int            /* iu */,
    lapack_int *            /* m */,
    double *            /* w */,
    lapack_complex_double *            /* z */,
    lapack_int            /* ldz */,
    lapack_int            /* nzc */,
    lapack_int *            /* isuppz */,
    lapack_logical *            /* tryrac */
);
static PFNLAPACKE_zstemr _g_LAPACKE_zstemr = NULL;
lapack_int LAPACKE_zstemr(
    int            matrix_layout,
    char            jobz,
    char            range,
    lapack_int            n,
    double *            d,
    double *            e,
    double            vl,
    double            vu,
    lapack_int            il,
    lapack_int            iu,
    lapack_int *            m,
    double *            w,
    lapack_complex_double *            z,
    lapack_int            ldz,
    lapack_int            nzc,
    lapack_int *            isuppz,
    lapack_logical *            tryrac
)
{
    if(_g_LAPACKE_zstemr==NULL) {
        _g_LAPACKE_zstemr = rindow_load_libopenblas_func("LAPACKE_zstemr"); 
        if(_g_LAPACKE_zstemr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zstemr(
        matrix_layout,
        jobz,
        range,
        n,
        d,
        e,
        vl,
        vu,
        il,
        iu,
        m,
        w,
        z,
        ldz,
        nzc,
        isuppz,
        tryrac    
    );
}
