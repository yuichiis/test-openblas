#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlapmt_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlapmt_work)( /* LAPACKE_dlapmt_work */
    int            /* matrix_layout */,
    lapack_logical            /* forwrd */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    double *            /* x */,
    lapack_int            /* ldx */,
    lapack_int *            /* k */
);
static PFNLAPACKE_dlapmt_work _g_LAPACKE_dlapmt_work = NULL;
lapack_int LAPACKE_dlapmt_work(
    int            matrix_layout,
    lapack_logical            forwrd,
    lapack_int            m,
    lapack_int            n,
    double *            x,
    lapack_int            ldx,
    lapack_int *            k
)
{
    if(_g_LAPACKE_dlapmt_work==NULL) {
        _g_LAPACKE_dlapmt_work = rindow_load_libopenblas_func("LAPACKE_dlapmt_work"); 
        if(_g_LAPACKE_dlapmt_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlapmt_work(
        matrix_layout,
        forwrd,
        m,
        n,
        x,
        ldx,
        k    
    );
}
