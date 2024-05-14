#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sggrqf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sggrqf)( /* LAPACKE_sggrqf */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    float *            /* taua */,
    float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* taub */
);
static PFNLAPACKE_sggrqf _g_LAPACKE_sggrqf = NULL;
lapack_int LAPACKE_sggrqf(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            p,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    float *            taua,
    float *            b,
    lapack_int            ldb,
    float *            taub
)
{
    if(_g_LAPACKE_sggrqf==NULL) {
        _g_LAPACKE_sggrqf = rindow_load_libopenblas_func("LAPACKE_sggrqf"); 
        if(_g_LAPACKE_sggrqf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sggrqf(
        matrix_layout,
        m,
        p,
        n,
        a,
        lda,
        taua,
        b,
        ldb,
        taub    
    );
}
