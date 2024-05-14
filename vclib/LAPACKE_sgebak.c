#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgebak not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgebak)( /* LAPACKE_sgebak */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* side */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    const float *            /* scale */,
    lapack_int            /* m */,
    float *            /* v */,
    lapack_int            /* ldv */
);
static PFNLAPACKE_sgebak _g_LAPACKE_sgebak = NULL;
lapack_int LAPACKE_sgebak(
    int            matrix_layout,
    char            job,
    char            side,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    const float *            scale,
    lapack_int            m,
    float *            v,
    lapack_int            ldv
)
{
    if(_g_LAPACKE_sgebak==NULL) {
        _g_LAPACKE_sgebak = rindow_load_libopenblas_func("LAPACKE_sgebak"); 
        if(_g_LAPACKE_sgebak==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgebak(
        matrix_layout,
        job,
        side,
        n,
        ilo,
        ihi,
        scale,
        m,
        v,
        ldv    
    );
}
