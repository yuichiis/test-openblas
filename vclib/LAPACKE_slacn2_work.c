#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_slacn2_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_slacn2_work)( /* LAPACKE_slacn2_work */
    lapack_int            /* n */,
    float *            /* v */,
    float *            /* x */,
    lapack_int *            /* isgn */,
    float *            /* est */,
    lapack_int *            /* kase */,
    lapack_int *            /* isave */
);
static PFNLAPACKE_slacn2_work _g_LAPACKE_slacn2_work = NULL;
lapack_int LAPACKE_slacn2_work(
    lapack_int            n,
    float *            v,
    float *            x,
    lapack_int *            isgn,
    float *            est,
    lapack_int *            kase,
    lapack_int *            isave
)
{
    if(_g_LAPACKE_slacn2_work==NULL) {
        _g_LAPACKE_slacn2_work = rindow_load_libopenblas_func("LAPACKE_slacn2_work"); 
        if(_g_LAPACKE_slacn2_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_slacn2_work(
        n,
        v,
        x,
        isgn,
        est,
        kase,
        isave    
    );
}
