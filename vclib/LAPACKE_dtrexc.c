#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dtrexc not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dtrexc)( /* LAPACKE_dtrexc */
    int            /* matrix_layout */,
    char            /* compq */,
    lapack_int            /* n */,
    double *            /* t */,
    lapack_int            /* ldt */,
    double *            /* q */,
    lapack_int            /* ldq */,
    lapack_int *            /* ifst */,
    lapack_int *            /* ilst */
);
static PFNLAPACKE_dtrexc _g_LAPACKE_dtrexc = NULL;
lapack_int LAPACKE_dtrexc(
    int            matrix_layout,
    char            compq,
    lapack_int            n,
    double *            t,
    lapack_int            ldt,
    double *            q,
    lapack_int            ldq,
    lapack_int *            ifst,
    lapack_int *            ilst
)
{
    if(_g_LAPACKE_dtrexc==NULL) {
        _g_LAPACKE_dtrexc = rindow_load_libopenblas_func("LAPACKE_dtrexc"); 
        if(_g_LAPACKE_dtrexc==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dtrexc(
        matrix_layout,
        compq,
        n,
        t,
        ldt,
        q,
        ldq,
        ifst,
        ilst    
    );
}
