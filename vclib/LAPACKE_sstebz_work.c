#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sstebz_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sstebz_work)( /* LAPACKE_sstebz_work */
    char            /* range */,
    char            /* order */,
    lapack_int            /* n */,
    float            /* vl */,
    float            /* vu */,
    lapack_int            /* il */,
    lapack_int            /* iu */,
    float            /* abstol */,
    const float *            /* d */,
    const float *            /* e */,
    lapack_int *            /* m */,
    lapack_int *            /* nsplit */,
    float *            /* w */,
    lapack_int *            /* iblock */,
    lapack_int *            /* isplit */,
    float *            /* work */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_sstebz_work _g_LAPACKE_sstebz_work = NULL;
lapack_int LAPACKE_sstebz_work(
    char            range,
    char            order,
    lapack_int            n,
    float            vl,
    float            vu,
    lapack_int            il,
    lapack_int            iu,
    float            abstol,
    const float *            d,
    const float *            e,
    lapack_int *            m,
    lapack_int *            nsplit,
    float *            w,
    lapack_int *            iblock,
    lapack_int *            isplit,
    float *            work,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_sstebz_work==NULL) {
        _g_LAPACKE_sstebz_work = rindow_load_libopenblas_func("LAPACKE_sstebz_work"); 
        if(_g_LAPACKE_sstebz_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sstebz_work(
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
