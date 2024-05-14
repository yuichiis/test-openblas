#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_stgsna not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_stgsna)( /* LAPACKE_stgsna */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* howmny */,
    const lapack_logical *            /* select */,
    lapack_int            /* n */,
    const float *            /* a */,
    lapack_int            /* lda */,
    const float *            /* b */,
    lapack_int            /* ldb */,
    const float *            /* vl */,
    lapack_int            /* ldvl */,
    const float *            /* vr */,
    lapack_int            /* ldvr */,
    float *            /* s */,
    float *            /* dif */,
    lapack_int            /* mm */,
    lapack_int *            /* m */
);
static PFNLAPACKE_stgsna _g_LAPACKE_stgsna = NULL;
lapack_int LAPACKE_stgsna(
    int            matrix_layout,
    char            job,
    char            howmny,
    const lapack_logical *            select,
    lapack_int            n,
    const float *            a,
    lapack_int            lda,
    const float *            b,
    lapack_int            ldb,
    const float *            vl,
    lapack_int            ldvl,
    const float *            vr,
    lapack_int            ldvr,
    float *            s,
    float *            dif,
    lapack_int            mm,
    lapack_int *            m
)
{
    if(_g_LAPACKE_stgsna==NULL) {
        _g_LAPACKE_stgsna = rindow_load_libopenblas_func("LAPACKE_stgsna"); 
        if(_g_LAPACKE_stgsna==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_stgsna(
        matrix_layout,
        job,
        howmny,
        select,
        n,
        a,
        lda,
        b,
        ldb,
        vl,
        ldvl,
        vr,
        ldvr,
        s,
        dif,
        mm,
        m    
    );
}
