#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_zhseqr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_zhseqr)( /* LAPACKE_zhseqr */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* compz */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    lapack_complex_double *            /* h */,
    lapack_int            /* ldh */,
    lapack_complex_double *            /* w */,
    lapack_complex_double *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_zhseqr _g_LAPACKE_zhseqr = NULL;
lapack_int LAPACKE_zhseqr(
    int            matrix_layout,
    char            job,
    char            compz,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    lapack_complex_double *            h,
    lapack_int            ldh,
    lapack_complex_double *            w,
    lapack_complex_double *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_zhseqr==NULL) {
        _g_LAPACKE_zhseqr = rindow_load_libopenblas_func("LAPACKE_zhseqr"); 
        if(_g_LAPACKE_zhseqr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_zhseqr(
        matrix_layout,
        job,
        compz,
        n,
        ilo,
        ihi,
        h,
        ldh,
        w,
        z,
        ldz    
    );
}
