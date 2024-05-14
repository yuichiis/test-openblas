#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgbbrd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgbbrd_work)( /* LAPACKE_dgbbrd_work */
    int            /* matrix_layout */,
    char            /* vect */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* ncc */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    double *            /* ab */,
    lapack_int            /* ldab */,
    double *            /* d */,
    double *            /* e */,
    double *            /* q */,
    lapack_int            /* ldq */,
    double *            /* pt */,
    lapack_int            /* ldpt */,
    double *            /* c */,
    lapack_int            /* ldc */,
    double *            /* work */
);
static PFNLAPACKE_dgbbrd_work _g_LAPACKE_dgbbrd_work = NULL;
lapack_int LAPACKE_dgbbrd_work(
    int            matrix_layout,
    char            vect,
    lapack_int            m,
    lapack_int            n,
    lapack_int            ncc,
    lapack_int            kl,
    lapack_int            ku,
    double *            ab,
    lapack_int            ldab,
    double *            d,
    double *            e,
    double *            q,
    lapack_int            ldq,
    double *            pt,
    lapack_int            ldpt,
    double *            c,
    lapack_int            ldc,
    double *            work
)
{
    if(_g_LAPACKE_dgbbrd_work==NULL) {
        _g_LAPACKE_dgbbrd_work = rindow_load_libopenblas_func("LAPACKE_dgbbrd_work"); 
        if(_g_LAPACKE_dgbbrd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgbbrd_work(
        matrix_layout,
        vect,
        m,
        n,
        ncc,
        kl,
        ku,
        ab,
        ldab,
        d,
        e,
        q,
        ldq,
        pt,
        ldpt,
        c,
        ldc,
        work    
    );
}
