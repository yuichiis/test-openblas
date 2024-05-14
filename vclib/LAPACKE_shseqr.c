#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_shseqr not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_shseqr)( /* LAPACKE_shseqr */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* compz */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    float *            /* h */,
    lapack_int            /* ldh */,
    float *            /* wr */,
    float *            /* wi */,
    float *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_shseqr _g_LAPACKE_shseqr = NULL;
lapack_int LAPACKE_shseqr(
    int            matrix_layout,
    char            job,
    char            compz,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    float *            h,
    lapack_int            ldh,
    float *            wr,
    float *            wi,
    float *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_shseqr==NULL) {
        _g_LAPACKE_shseqr = rindow_load_libopenblas_func("LAPACKE_shseqr"); 
        if(_g_LAPACKE_shseqr==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_shseqr(
        matrix_layout,
        job,
        compz,
        n,
        ilo,
        ihi,
        h,
        ldh,
        wr,
        wi,
        z,
        ldz    
    );
}
