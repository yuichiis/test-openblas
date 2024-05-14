#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgebal not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgebal)( /* LAPACKE_sgebal */
    int            /* matrix_layout */,
    char            /* job */,
    lapack_int            /* n */,
    float *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* ilo */,
    lapack_int *            /* ihi */,
    float *            /* scale */
);
static PFNLAPACKE_sgebal _g_LAPACKE_sgebal = NULL;
lapack_int LAPACKE_sgebal(
    int            matrix_layout,
    char            job,
    lapack_int            n,
    float *            a,
    lapack_int            lda,
    lapack_int *            ilo,
    lapack_int *            ihi,
    float *            scale
)
{
    if(_g_LAPACKE_sgebal==NULL) {
        _g_LAPACKE_sgebal = rindow_load_libopenblas_func("LAPACKE_sgebal"); 
        if(_g_LAPACKE_sgebal==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgebal(
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
