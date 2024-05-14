#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zlangb_work not found\n";
typedef double (CALLBACK* PFNLAPACKE_zlangb_work)( /* LAPACKE_zlangb_work */
    int            /* matrix_layout */,
    char            /* norm */,
    lapack_int            /* n */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    const lapack_complex_double *            /* ab */,
    lapack_int            /* ldab */,
    double *            /* work */
);
static PFNLAPACKE_zlangb_work _g_LAPACKE_zlangb_work = NULL;
double LAPACKE_zlangb_work(
    int            matrix_layout,
    char            norm,
    lapack_int            n,
    lapack_int            kl,
    lapack_int            ku,
    const lapack_complex_double *            ab,
    lapack_int            ldab,
    double *            work
)
{
    if(_g_LAPACKE_zlangb_work==NULL) {
        _g_LAPACKE_zlangb_work = rindow_load_libopenblas_func("LAPACKE_zlangb_work"); 
        if(_g_LAPACKE_zlangb_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zlangb_work(
        matrix_layout,
        norm,
        n,
        kl,
        ku,
        ab,
        ldab,
        work    
    );
}
