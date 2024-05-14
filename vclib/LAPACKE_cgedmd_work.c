#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_cgedmd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_cgedmd_work)( /* LAPACKE_cgedmd_work */
    int            /* matrix_layout */,
    char            /* jobs */,
    char            /* jobz */,
    char            /* jobr */,
    char            /* jobf */,
    lapack_int            /* whtsvd */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_complex_float *            /* x */,
    lapack_int            /* ldx */,
    lapack_complex_float *            /* y */,
    lapack_int            /* ldy */,
    lapack_int            /* nrnk */,
    float *            /* tol */,
    lapack_int            /* k */,
    lapack_complex_float *            /* eigs */,
    lapack_complex_float *            /* z */,
    lapack_int            /* ldz */,
    float *            /* res */,
    lapack_complex_float *            /* b */,
    lapack_int            /* ldb */,
    lapack_complex_float *            /* w */,
    lapack_int            /* ldw */,
    lapack_complex_float *            /* s */,
    lapack_int            /* lds */,
    lapack_complex_float *            /* zwork */,
    lapack_int            /* lzwork */,
    float *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */
);
static PFNLAPACKE_cgedmd_work _g_LAPACKE_cgedmd_work = NULL;
lapack_int LAPACKE_cgedmd_work(
    int            matrix_layout,
    char            jobs,
    char            jobz,
    char            jobr,
    char            jobf,
    lapack_int            whtsvd,
    lapack_int            m,
    lapack_int            n,
    lapack_complex_float *            x,
    lapack_int            ldx,
    lapack_complex_float *            y,
    lapack_int            ldy,
    lapack_int            nrnk,
    float *            tol,
    lapack_int            k,
    lapack_complex_float *            eigs,
    lapack_complex_float *            z,
    lapack_int            ldz,
    float *            res,
    lapack_complex_float *            b,
    lapack_int            ldb,
    lapack_complex_float *            w,
    lapack_int            ldw,
    lapack_complex_float *            s,
    lapack_int            lds,
    lapack_complex_float *            zwork,
    lapack_int            lzwork,
    float *            work,
    lapack_int            lwork,
    lapack_int *            iwork,
    lapack_int            liwork
)
{
    if(_g_LAPACKE_cgedmd_work==NULL) {
        _g_LAPACKE_cgedmd_work = rindow_load_libopenblas_func("LAPACKE_cgedmd_work"); 
        if(_g_LAPACKE_cgedmd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_cgedmd_work(
        matrix_layout,
        jobs,
        jobz,
        jobr,
        jobf,
        whtsvd,
        m,
        n,
        x,
        ldx,
        y,
        ldy,
        nrnk,
        tol,
        k,
        eigs,
        z,
        ldz,
        res,
        b,
        ldb,
        w,
        ldw,
        s,
        lds,
        zwork,
        lzwork,
        work,
        lwork,
        iwork,
        liwork    
    );
}
