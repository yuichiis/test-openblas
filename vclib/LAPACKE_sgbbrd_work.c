#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_sgbbrd_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_sgbbrd_work)( /* LAPACKE_sgbbrd_work */
    int            /* matrix_layout */,
    char            /* vect */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    lapack_int            /* ncc */,
    lapack_int            /* kl */,
    lapack_int            /* ku */,
    float *            /* ab */,
    lapack_int            /* ldab */,
    float *            /* d */,
    float *            /* e */,
    float *            /* q */,
    lapack_int            /* ldq */,
    float *            /* pt */,
    lapack_int            /* ldpt */,
    float *            /* c */,
    lapack_int            /* ldc */,
    float *            /* work */
);
static PFNLAPACKE_sgbbrd_work _g_LAPACKE_sgbbrd_work = NULL;
lapack_int LAPACKE_sgbbrd_work(
    int            matrix_layout,
    char            vect,
    lapack_int            m,
    lapack_int            n,
    lapack_int            ncc,
    lapack_int            kl,
    lapack_int            ku,
    float *            ab,
    lapack_int            ldab,
    float *            d,
    float *            e,
    float *            q,
    lapack_int            ldq,
    float *            pt,
    lapack_int            ldpt,
    float *            c,
    lapack_int            ldc,
    float *            work
)
{
    if(_g_LAPACKE_sgbbrd_work==NULL) {
        _g_LAPACKE_sgbbrd_work = rindow_load_libopenblas_func("LAPACKE_sgbbrd_work"); 
        if(_g_LAPACKE_sgbbrd_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_sgbbrd_work(
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
