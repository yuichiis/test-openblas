#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgebal not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgebal)( /* LAPACKE_zgebal */
    int            /* matrix_layout */,
    char            /* job */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* ilo */,
    lapack_int *            /* ihi */,
    double *            /* scale */
);
static PFNLAPACKE_zgebal _g_LAPACKE_zgebal = NULL;
lapack_int LAPACKE_zgebal(
    int            matrix_layout,
    char            job,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_int *            ilo,
    lapack_int *            ihi,
    double *            scale
)
{
    if(_g_LAPACKE_zgebal==NULL) {
        _g_LAPACKE_zgebal = rindow_load_libopenblas_func("LAPACKE_zgebal"); 
        if(_g_LAPACKE_zgebal==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgebal(
        matrix_layout,
        job,
        n,
        a,
        lda,
        ilo,
        ihi,
        scale    
    );
}
