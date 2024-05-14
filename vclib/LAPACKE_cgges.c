#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgges not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgges)( /* LAPACKE_cgges */
    int            /* matrix_layout */,
    char            /* jobvsl */,
    char            /* jobvsr */,
    char            /* sort */,
    LAPACK_C_SELECT2            /* selctg */,
    lapack_int            /* n */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_int *            /* sdim */,
    lapack_complex_float *            /* alpha */,
    lapack_complex_float *            /* beta */,
    lapack_complex_float *            /* vsl */,
    lapack_int            /* ldvsl */,
    lapack_complex_float *            /* vsr */,
    lapack_int            /* ldvsr */
);
static PFNLAPACKE_cgges _g_LAPACKE_cgges = NULL;
lapack_int LAPACKE_cgges(
    int            matrix_layout,
    char            jobvsl,
    char            jobvsr,
    char            sort,
    LAPACK_C_SELECT2            selctg,
    lapack_int            n,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_int *            sdim,
    lapack_complex_float *            alpha,
    lapack_complex_float *            beta,
    lapack_complex_float *            vsl,
    lapack_int            ldvsl,
    lapack_complex_float *            vsr,
    lapack_int            ldvsr
)
{
    if(_g_LAPACKE_cgges==NULL) {
        _g_LAPACKE_cgges = rindow_load_libopenblas_func("LAPACKE_cgges"); 
        if(_g_LAPACKE_cgges==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgges(
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
