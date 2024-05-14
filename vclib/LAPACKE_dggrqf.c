#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dggrqf not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dggrqf)( /* LAPACKE_dggrqf */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* p */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* taua */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* taub */
);
static PFNLAPACKE_dggrqf _g_LAPACKE_dggrqf = NULL;
lapack_int LAPACKE_dggrqf(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            p,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            taua,
    double *            b,
    lapack_int            ldb,
    double *            taub
)
{
    if(_g_LAPACKE_dggrqf==NULL) {
        _g_LAPACKE_dggrqf = rindow_load_libopenblas_func("LAPACKE_dggrqf"); 
        if(_g_LAPACKE_dggrqf==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dggrqf(
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
