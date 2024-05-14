#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sbdsvdx_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sbdsvdx_work)( /* LAPACKE_sbdsvdx_work */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* jobz */,
    char            /* range */,
    lapack_int            /* n */,
    float *            /* d */,
    float *            /* e */,
    float            /* vl */,
    float            /* vu */,
    lapack_int            /* il */,
    lapack_int            /* iu */,
    lapack_int *            /* ns */,
    float *            /* s */,
    float *            /* z */,
    lapack_int            /* ldz */,
    float *            /* work */,
    lapack_int *            /* iwork */
);
static PFNLAPACKE_sbdsvdx_work _g_LAPACKE_sbdsvdx_work = NULL;
lapack_int LAPACKE_sbdsvdx_work(
    int            matrix_layout,
    char            uplo,
    char            jobz,
    char            range,
    lapack_int            n,
    float *            d,
    float *            e,
    float            vl,
    float            vu,
    lapack_int            il,
    lapack_int            iu,
    lapack_int *            ns,
    float *            s,
    float *            z,
    lapack_int            ldz,
    float *            work,
    lapack_int *            iwork
)
{
    if(_g_LAPACKE_sbdsvdx_work==NULL) {
        _g_LAPACKE_sbdsvdx_work = rindow_load_libopenblas_func("LAPACKE_sbdsvdx_work"); 
        if(_g_LAPACKE_sbdsvdx_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sbdsvdx_work(
        matrix_layout,
        uplo,
        jobz,
        range,
        n,
        d,
        e,
        vl,
        vu,
        il,
        iu,
        ns,
        s,
        z,
        ldz,
        work,
        iwork    
    );
}
