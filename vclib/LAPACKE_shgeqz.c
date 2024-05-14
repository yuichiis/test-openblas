#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_shgeqz not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_shgeqz)( /* LAPACKE_shgeqz */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* compq */,
    char            /* compz */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    float *            /* h */,
    lapack_int            /* ldh */,
    float *            /* t */,
    lapack_int            /* ldt */,
    float *            /* alphar */,
    float *            /* alphai */,
    float *            /* beta */,
    float *            /* q */,
    lapack_int            /* ldq */,
    float *            /* z */,
    lapack_int            /* ldz */
);
static PFNLAPACKE_shgeqz _g_LAPACKE_shgeqz = NULL;
lapack_int LAPACKE_shgeqz(
    int            matrix_layout,
    char            job,
    char            compq,
    char            compz,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    float *            h,
    lapack_int            ldh,
    float *            t,
    lapack_int            ldt,
    float *            alphar,
    float *            alphai,
    float *            beta,
    float *            q,
    lapack_int            ldq,
    float *            z,
    lapack_int            ldz
)
{
    if(_g_LAPACKE_shgeqz==NULL) {
        _g_LAPACKE_shgeqz = rindow_load_libopenblas_func("LAPACKE_shgeqz"); 
        if(_g_LAPACKE_shgeqz==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_shgeqz(
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
        alphar,
        alphai,
        beta,
        q,
        ldq,
        z,
        ldz    
    );
}
