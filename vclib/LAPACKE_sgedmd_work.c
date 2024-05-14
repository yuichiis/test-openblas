#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgedmd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgedmd_work)( /* LAPACKE_sgedmd_work */
    int            /* matrix_layout */,
    char            /* jobs */,
    char            /* jobz */,
    char            /* jobr */,
    char            /* jobf */,
    lapack_int            /* whtsvd */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    float *            /* x */,
    lapack_int            /* ldx */,
    float *            /* y */,
    lapack_int            /* ldy */,
    lapack_int            /* nrnk */,
    float *            /* tol */,
    lapack_int            /* k */,
    float *            /* reig */,
    float *            /* imeig */,
    float *            /* z */,
    lapack_int            /* ldz */,
    float *            /* res */,
    float *            /* b */,
    lapack_int            /* ldb */,
    float *            /* w */,
    lapack_int            /* ldw */,
    float *            /* s */,
    lapack_int            /* lds */,
    float *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */
);
static PFNLAPACKE_sgedmd_work _g_LAPACKE_sgedmd_work = NULL;
lapack_int LAPACKE_sgedmd_work(
    int            matrix_layout,
    char            jobs,
    char            jobz,
    char            jobr,
    char            jobf,
    lapack_int            whtsvd,
    lapack_int            m,
    lapack_int            n,
    float *            x,
    lapack_int            ldx,
    float *            y,
    lapack_int            ldy,
    lapack_int            nrnk,
    float *            tol,
    lapack_int            k,
    float *            reig,
    float *            imeig,
    float *            z,
    lapack_int            ldz,
    float *            res,
    float *            b,
    lapack_int            ldb,
    float *            w,
    lapack_int            ldw,
    float *            s,
    lapack_int            lds,
    float *            work,
    lapack_int            lwork,
    lapack_int *            iwork,
    lapack_int            liwork
)
{
    if(_g_LAPACKE_sgedmd_work==NULL) {
        _g_LAPACKE_sgedmd_work = rindow_load_libopenblas_func("LAPACKE_sgedmd_work"); 
        if(_g_LAPACKE_sgedmd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgedmd_work(
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
        reig,
        imeig,
        z,
        ldz,
        res,
        b,
        ldb,
        w,
        ldw,
        s,
        lds,
        work,
        lwork,
        iwork,
        liwork    
    );
}
