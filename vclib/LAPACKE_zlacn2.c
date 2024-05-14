#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlacn2 not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zlacn2)( /* LAPACKE_zlacn2 */
    lapack_int            /* n */,
    lapack_complex_double *            /* v */,
    lapack_complex_double *            /* x */,
    double *            /* est */,
    lapack_int *            /* kase */,
    lapack_int *            /* isave */
);
static PFNLAPACKE_zlacn2 _g_LAPACKE_zlacn2 = NULL;
lapack_int LAPACKE_zlacn2(
    lapack_int            n,
    lapack_complex_double *            v,
    lapack_complex_double *            x,
    double *            est,
    lapack_int *            kase,
    lapack_int *            isave
)
{
    if(_g_LAPACKE_zlacn2==NULL) {
        _g_LAPACKE_zlacn2 = rindow_load_libopenblas_func("LAPACKE_zlacn2"); 
        if(_g_LAPACKE_zlacn2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlacn2(
        n,
        v,
        x,
        est,
        kase,
        isave    
    );
}
