#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sbdsdc not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sbdsdc)( /* LAPACKE_sbdsdc */
    int            /* matrix_layout */,
    char            /* uplo */,
    char            /* compq */,
    lapack_int            /* n */,
    float *            /* d */,
    float *            /* e */,
    float *            /* u */,
    lapack_int            /* ldu */,
    float *            /* vt */,
    lapack_int            /* ldvt */,
    float *            /* q */,
    lapack_int *            /* iq */
);
static PFNLAPACKE_sbdsdc _g_LAPACKE_sbdsdc = NULL;
lapack_int LAPACKE_sbdsdc(
    int            matrix_layout,
    char            uplo,
    char            compq,
    lapack_int            n,
    float *            d,
    float *            e,
    float *            u,
    lapack_int            ldu,
    float *            vt,
    lapack_int            ldvt,
    float *            q,
    lapack_int *            iq
)
{
    if(_g_LAPACKE_sbdsdc==NULL) {
        _g_LAPACKE_sbdsdc = rindow_load_libopenblas_func("LAPACKE_sbdsdc"); 
        if(_g_LAPACKE_sbdsdc==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sbdsdc(
        matrix_layout,
        uplo,
        compq,
        n,
        d,
        e,
        u,
        ldu,
        vt,
        ldvt,
        q,
        iq    
    );
}
