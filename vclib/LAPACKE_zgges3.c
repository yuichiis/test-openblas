#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zgges3 not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zgges3)( /* LAPACKE_zgges3 */
    int            /* matrix_layout */,
    char            /* jobvsl */,
    char            /* jobvsr */,
    char            /* sort */,
    LAPACK_Z_SELECT2            /* selctg */,
    lapack_int            /* n */,
    lapack_complex_double *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_double *            /* b */,
    lapack_int            /* ldb */,
    lapack_int *            /* sdim */,
    lapack_complex_double *            /* alpha */,
    lapack_complex_double *            /* beta */,
    lapack_complex_double *            /* vsl */,
    lapack_int            /* ldvsl */,
    lapack_complex_double *            /* vsr */,
    lapack_int            /* ldvsr */
);
static PFNLAPACKE_zgges3 _g_LAPACKE_zgges3 = NULL;
lapack_int LAPACKE_zgges3(
    int            matrix_layout,
    char            jobvsl,
    char            jobvsr,
    char            sort,
    LAPACK_Z_SELECT2            selctg,
    lapack_int            n,
    lapack_complex_double *            a,
    lapack_int            lda,
    lapack_complex_double *            b,
    lapack_int            ldb,
    lapack_int *            sdim,
    lapack_complex_double *            alpha,
    lapack_complex_double *            beta,
    lapack_complex_double *            vsl,
    lapack_int            ldvsl,
    lapack_complex_double *            vsr,
    lapack_int            ldvsr
)
{
    if(_g_LAPACKE_zgges3==NULL) {
        _g_LAPACKE_zgges3 = rindow_load_libopenblas_func("LAPACKE_zgges3"); 
        if(_g_LAPACKE_zgges3==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zgges3(
        matrix_layout,
        jobvsl,
        jobvsr,
        sort,
        selctg,
        n,
        a,
        lda,
        b,
        ldb,
        sdim,
        alpha,
        beta,
        vsl,
        ldvsl,
        vsr,
        ldvsr    
    );
}
