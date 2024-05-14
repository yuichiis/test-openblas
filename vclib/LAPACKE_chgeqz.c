#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_chgeqz not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_chgeqz)( /* LAPACKE_chgeqz */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* compq */,
    char            /* compz */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    lapack_complex_float *            /* h */,
    lapack_int            /* ldh */,
    lapack_complex_float *            /* t */,
    lapack_int            /* ldt */,
    lapack_complex_float *            /* alpha */,
    lapack_complex_float *            /* beta */,
    lapack_complex_float *            /* q */,
    lapack_int            /* ldq */,
    lapack_complex_float *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_chgeqz _g_LAPACKE_chgeqz = NULL;
lapack_int LAPACKE_chgeqz(
    int            matrix_layout,
    char            job,
    char            compq,
    char            compz,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    lapack_complex_float *            h,
    lapack_int            ldh,
    lapack_complex_float *            t,
    lapack_int            ldt,
    lapack_complex_float *            alpha,
    lapack_complex_float *            beta,
    lapack_complex_float *            q,
    lapack_int            ldq,
    lapack_complex_float *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_chgeqz==NULL) {
        _g_LAPACKE_chgeqz = rindow_load_libopenblas_func("LAPACKE_chgeqz"); 
        if(_g_LAPACKE_chgeqz==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_chgeqz(
        matrix_layout,
        job,
        compq,
        compz,
        n,
        ilo,
        ihi,
        h,
        ldh,
        t,
        ldt,
        alpha,
        beta,
        q,
        ldq,
        z,
        ldz    
    );
}
