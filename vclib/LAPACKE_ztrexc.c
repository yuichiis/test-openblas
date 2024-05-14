#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ztrexc not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ztrexc)( /* LAPACKE_ztrexc */
    int            /* matrix_layout */,
    char            /* compq */,
    lapack_int            /* n */,
    lapack_complex_double *            /* t */,
    lapack_int            /* ldt */,
    lapack_complex_double *            /* q */,
    lapack_int            /* ldq */,
    lapack_int            /* ifst */,
    lapack_int            /* ilst */
);
static PFNLAPACKE_ztrexc _g_LAPACKE_ztrexc = NULL;
lapack_int LAPACKE_ztrexc(
    int            matrix_layout,
    char            compq,
    lapack_int            n,
    lapack_complex_double *            t,
    lapack_int            ldt,
    lapack_complex_double *            q,
    lapack_int            ldq,
    lapack_int            ifst,
    lapack_int            ilst
)
{
    if(_g_LAPACKE_ztrexc==NULL) {
        _g_LAPACKE_ztrexc = rindow_load_libopenblas_func("LAPACKE_ztrexc"); 
        if(_g_LAPACKE_ztrexc==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ztrexc(
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
