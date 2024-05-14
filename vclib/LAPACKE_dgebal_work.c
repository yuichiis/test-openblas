#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgebal_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgebal_work)( /* LAPACKE_dgebal_work */
    int            /* matrix_layout */,
    char            /* job */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    lapack_int *            /* ilo */,
    lapack_int *            /* ihi */,
    double *            /* scale */
);
static PFNLAPACKE_dgebal_work _g_LAPACKE_dgebal_work = NULL;
lapack_int LAPACKE_dgebal_work(
    int            matrix_layout,
    char            job,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    lapack_int *            ilo,
    lapack_int *            ihi,
    double *            scale
)
{
    if(_g_LAPACKE_dgebal_work==NULL) {
        _g_LAPACKE_dgebal_work = rindow_load_libopenblas_func("LAPACKE_dgebal_work"); 
        if(_g_LAPACKE_dgebal_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgebal_work(
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
