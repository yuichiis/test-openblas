#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgetf2 not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgetf2)( /* LAPACKE_sgetf2 */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* ipiv */
);
static PFNLAPACKE_sgetf2 _g_LAPACKE_sgetf2 = NULL;
lapack_int LAPACKE_sgetf2(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    lapack_int *            ipiv
)
{
    if(_g_LAPACKE_sgetf2==NULL) {
        _g_LAPACKE_sgetf2 = rindow_load_libopenblas_func("LAPACKE_sgetf2"); 
        if(_g_LAPACKE_sgetf2==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgetf2(
        matrix_layout,
        m,
        n,
        a,
        lda,
        ipiv    
    );
}
