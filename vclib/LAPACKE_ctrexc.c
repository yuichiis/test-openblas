#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_ctrexc not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_ctrexc)( /* LAPACKE_ctrexc */
    int            /* matrix_layout */,
    char            /* compq */,
    lapack_int            /* n */,
    lapack_complex_float *            /* t */,
    lapack_int            /* ldt */,
    lapack_complex_float *            /* q */,
    lapack_int            /* ldq */,
    lapack_int            /* ifst */,
    lapack_int            /* ilst */
);
static PFNLAPACKE_ctrexc _g_LAPACKE_ctrexc = NULL;
lapack_int LAPACKE_ctrexc(
    int            matrix_layout,
    char            compq,
    lapack_int            n,
    lapack_complex_float *            t,
    lapack_int            ldt,
    lapack_complex_float *            q,
    lapack_int            ldq,
    lapack_int            ifst,
    lapack_int            ilst
)
{
    if(_g_LAPACKE_ctrexc==NULL) {
        _g_LAPACKE_ctrexc = rindow_load_libopenblas_func("LAPACKE_ctrexc"); 
        if(_g_LAPACKE_ctrexc==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_ctrexc(
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
