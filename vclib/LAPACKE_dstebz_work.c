#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dstebz_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dstebz_work)( /* LAPACKE_dstebz_work */
    char            /* range */,
    char            /* order */,
    lapack_int            /* n */,
    double            /* vl */,
    double            /* vu */,
    lapack_int            /* il */,
    lapack_int            /* iu */,
    double            /* abstol */,
    const double *            /* d */,
    const double *            /* e */,
    lapack_int *            /* m */,
    lapack_int *            /* nsplit */,
    double *            /* w */,
    lapack_int *            /* iblock */,
    lapack_int *            /* isplit */,
    double *            /* work */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_dstebz_work _g_LAPACKE_dstebz_work = NULL;
lapack_int LAPACKE_dstebz_work(
    char            range,
    char            order,
    lapack_int            n,
    double            vl,
    double            vu,
    lapack_int            il,
    lapack_int            iu,
    double            abstol,
    const double *            d,
    const double *            e,
    lapack_int *            m,
    lapack_int *            nsplit,
    double *            w,
    lapack_int *            iblock,
    lapack_int *            isplit,
    double *            work,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_dstebz_work==NULL) {
        _g_LAPACKE_dstebz_work = rindow_load_libopenblas_func("LAPACKE_dstebz_work"); 
        if(_g_LAPACKE_dstebz_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dstebz_work(
        range,
        order,
        n,
        vl,
        vu,
        il,
        iu,
        abstol,
        d,
        e,
        m,
        nsplit,
        w,
        iblock,
        isplit,
        work,
        iwork    
    );
}
