#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgebal not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgebal)( /* LAPACKE_cgebal */
    int            /* matrix_layout */,
    char            /* job */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* ilo */,
    lapack_int *            /* ihi */,
    float *            /* scale */
);
static PFNLAPACKE_cgebal _g_LAPACKE_cgebal = NULL;
lapack_int LAPACKE_cgebal(
    int            matrix_layout,
    char            job,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_int *            ilo,
    lapack_int *            ihi,
    float *            scale
)
{
    if(_g_LAPACKE_cgebal==NULL) {
        _g_LAPACKE_cgebal = rindow_load_libopenblas_func("LAPACKE_cgebal"); 
        if(_g_LAPACKE_cgebal==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgebal(
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
