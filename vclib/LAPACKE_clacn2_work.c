#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_clacn2_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_clacn2_work)( /* LAPACKE_clacn2_work */
    lapack_int            /* n */,
    lapack_complex_float *            /* v */,
    lapack_complex_float *            /* x */,
    float *            /* est */,
    lapack_int *            /* kase */,
    lapack_int *            /* isave */
);
static PFNLAPACKE_clacn2_work _g_LAPACKE_clacn2_work = NULL;
lapack_int LAPACKE_clacn2_work(
    lapack_int            n,
    lapack_complex_float *            v,
    lapack_complex_float *            x,
    float *            est,
    lapack_int *            kase,
    lapack_int *            isave
)
{
    if(_g_LAPACKE_clacn2_work==NULL) {
        _g_LAPACKE_clacn2_work = rindow_load_libopenblas_func("LAPACKE_clacn2_work"); 
        if(_g_LAPACKE_clacn2_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_clacn2_work(
        n,
        v,
        x,
        est,
        kase,
        isave    
    );
}
