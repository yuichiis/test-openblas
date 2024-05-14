#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgedmdq_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgedmdq_work)( /* LAPACKE_dgedmdq_work */
    int            /* matrix_layout */,
    char            /* jobs */,
    char            /* jobz */,
    char            /* jobr */,
    char            /* jobq */,
    char            /* jobt */,
    char            /* jobf */,
    lapack_int            /* whtsvd */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    double *            /* f */,
    lapack_int            /* ldf */,
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
    double *            /* v */,
    lapack_int            /* ldv */,
    double *            /* s */,
    lapack_int            /* lds */,
    double *            /* work */,
    lapack_int            /* lwork */,
    lapack_int *            /* iwork */,
    lapack_int            /* liwork */
);
static PFNLAPACKE_dgedmdq_work _g_LAPACKE_dgedmdq_work = NULL;
lapack_int LAPACKE_dgedmdq_work(
    int            matrix_layout,
    char            jobs,
    char            jobz,
    char            jobr,
    char            jobq,
    char            jobt,
    char            jobf,
    lapack_int            whtsvd,
    lapack_int            m,
    lapack_int            n,
    double *            f,
    lapack_int            ldf,
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
    double *            v,
    lapack_int            ldv,
    double *            s,
    lapack_int            lds,
    double *            work,
    lapack_int            lwork,
    lapack_int *            iwork,
    lapack_int            liwork
)
{
    if(_g_LAPACKE_dgedmdq_work==NULL) {
        _g_LAPACKE_dgedmdq_work = rindow_load_libopenblas_func("LAPACKE_dgedmdq_work"); 
        if(_g_LAPACKE_dgedmdq_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgedmdq_work(
        matrix_layout,
        jobs,
        jobz,
        jobr,
        jobq,
        jobt,
        jobf,
        whtsvd,
        m,
        n,
        f,
        ldf,
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
        v,
        ldv,
        s,
        lds,
        work,
        lwork,
        iwork,
        liwork    
    );
}
