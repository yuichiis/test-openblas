#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ddisna_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ddisna_work)( /* LAPACKE_ddisna_work */
    char            /* job */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    const double *            /* d */,
    double *            /* sep */
);
static PFNLAPACKE_ddisna_work _g_LAPACKE_ddisna_work = NULL;
lapack_int LAPACKE_ddisna_work(
    char            job,
    lapack_int            m,
    lapack_int            n,
    const double *            d,
    double *            sep
)
{
    if(_g_LAPACKE_ddisna_work==NULL) {
        _g_LAPACKE_ddisna_work = rindow_load_libopenblas_func("LAPACKE_ddisna_work"); 
        if(_g_LAPACKE_ddisna_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ddisna_work(
        job,
        m,
        n,
        d,
        sep    
    );
}
