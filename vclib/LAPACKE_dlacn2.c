#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dlacn2 not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dlacn2)( /* LAPACKE_dlacn2 */
    lapack_int            /* n */,
    double *            /* v */,
    double *            /* x */,
    lapack_int *            /* isgn */,
    double *            /* est */,
    lapack_int *            /* kase */,
    lapack_int *            /* isave */
);
static PFNLAPACKE_dlacn2 _g_LAPACKE_dlacn2 = NULL;
lapack_int LAPACKE_dlacn2(
    lapack_int            n,
    double *            v,
    double *            x,
    lapack_int *            isgn,
    double *            est,
    lapack_int *            kase,
    lapack_int *            isave
)
{
    if(_g_LAPACKE_dlacn2==NULL) {
        _g_LAPACKE_dlacn2 = rindow_load_libopenblas_func("LAPACKE_dlacn2"); 
        if(_g_LAPACKE_dlacn2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dlacn2(
        n,
        v,
        x,
        isgn,
        est,
        kase,
        isave    
    );
}
