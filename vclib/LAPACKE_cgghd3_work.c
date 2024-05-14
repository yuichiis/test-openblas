#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgghd3_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgghd3_work)( /* LAPACKE_cgghd3_work */
    int            /* matrix_layout */,
    char            /* compq */,
    char            /* compz */,
    lapack_int            /* n */,
    lapack_int            /* ilo */,
    lapack_int            /* ihi */,
    lapack_complex_float *            /* a */,
    lapack_int            /* lda */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* q */,
    lapack_int            /* ldq */,
    lapack_complex_float *            /* z */,
    lapack_int            /* ldz */,
    lapack_complex_float *            /* work */,
    lapack_int            /* lwork */
);
static PFNLAPACKE_cgghd3_work _g_LAPACKE_cgghd3_work = NULL;
lapack_int LAPACKE_cgghd3_work(
    int            matrix_layout,
    char            compq,
    char            compz,
    lapack_int            n,
    lapack_int            ilo,
    lapack_int            ihi,
    lapack_complex_float *            a,
    lapack_int            lda,
    lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            q,
    lapack_int            ldq,
    lapack_complex_float *            z,
    lapack_int            ldz,
    lapack_complex_float *            work,
    lapack_int            lwork
)
{
    if(_g_LAPACKE_cgghd3_work==NULL) {
        _g_LAPACKE_cgghd3_work = rindow_load_libopenblas_func("LAPACKE_cgghd3_work"); 
        if(_g_LAPACKE_cgghd3_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgghd3_work(
        matrix_layout,
        compq,
        compz,
        n,
        ilo,
        ihi,
        a,
        lda,
        b,
        ldb,
        q,
        ldq,
        z,
        ldz,
        work,
        lwork    
    );
}
