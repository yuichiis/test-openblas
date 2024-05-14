#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgedmd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgedmd_work)( /* LAPACKE_dgedmd_work */
    int            /* matrix_layout */,
    char            /* jobs */,
    char            /* jobz */,
    char            /* jobr */,
    char            /* jobf */,
    lapack_int            /* whtsvd */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    double *            /* x */,
    lapack_int            /* ldx */,
    double *            /* y */,
    lapack_int            /* ldy */,
    lapack_int            /* nrnk */,
    double *            /* tol */,
    lapack_int            /* k */,
    double *            /* reig */,
    double *            /* imeig */,
    double *            /* z */,
    lapack_int            /* ldz */,
    double *            /* res */,
    double *            /* b */,
    lapack_int            /* ldb */,
    double *            /* w */,
    lapack_int            /* ldw */,
    double *            /* s */,
    lapack_int            /* lds */,
    double *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */
);
static PFNLAPACKE_dgedmd_work _g_LAPACKE_dgedmd_work = NULL;
lapack_int LAPACKE_dgedmd_work(
    int            matrix_layout,
    char            jobs,
    char            jobz,
    char            jobr,
    char            jobf,
    lapack_int            whtsvd,
    lapack_int            m,
    lapack_int            n,
    double *            x,
    lapack_int            ldx,
    double *            y,
    lapack_int            ldy,
    lapack_int            nrnk,
    double *            tol,
    lapack_int            k,
    double *            reig,
    double *            imeig,
    double *            z,
    lapack_int            ldz,
    double *            res,
    double *            b,
    lapack_int            ldb,
    double *            w,
    lapack_int            ldw,
    double *            s,
    lapack_int            lds,
    double *            work,
    lapack_int            lwork,
    lapack_int *            iwork,
    lapack_int            liwork
)
{
    if(_g_LAPACKE_dgedmd_work==NULL) {
        _g_LAPACKE_dgedmd_work = rindow_load_libopenblas_func("LAPACKE_dgedmd_work"); 
        if(_g_LAPACKE_dgedmd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgedmd_work(
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
