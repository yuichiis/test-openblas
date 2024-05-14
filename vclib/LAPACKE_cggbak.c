#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cggbak not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cggbak)( /* LAPACKE_cggbak */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* side */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    const float *            /* lscale */,
    const float *            /* rscale */,
    lapack_int            /* m */,
    lapack_complex_float *            /* v */,
    lapack_int            /* ldv */
);
static PFNLAPACKE_cggbak _g_LAPACKE_cggbak = NULL;
lapack_int LAPACKE_cggbak(
    int            matrix_layout,
    char            job,
    char            side,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    const float *            lscale,
    const float *            rscale,
    lapack_int            m,
    lapack_complex_float *            v,
    lapack_int            ldv
)
{
    if(_g_LAPACKE_cggbak==NULL) {
        _g_LAPACKE_cggbak = rindow_load_libopenblas_func("LAPACKE_cggbak"); 
        if(_g_LAPACKE_cggbak==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cggbak(
        matrix_layout,
        job,
        side,
        n,
        ilo,
        ihi,
        lscale,
        rscale,
        m,
        v,
        ldv    
    );
}
