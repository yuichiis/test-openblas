#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_shsein_work not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_shsein_work)( /* LAPACKE_shsein_work */
    int            /* matrix_layout */,
    char            /* job */,
    char            /* eigsrc */,
    char            /* initv */,
    lapack_logical *            /* select */,
    lapack_int            /* n */,
    const float *            /* h */,
    lapack_int            /* ldh */,
    float *            /* wr */,
    const float *            /* wi */,
    float *            /* vl */,
    lapack_int            /* ldvl */,
    float *            /* vr */,
    lapack_int            /* ldvr */,
    lapack_int            /* mm */,
    lapack_int *            /* m */,
    float *            /* work */,
    lapack_int *            /* ifaill */,
    lapack_int *            /* ifailr */
);
static PFNLAPACKE_shsein_work _g_LAPACKE_shsein_work = NULL;
lapack_int LAPACKE_shsein_work(
    int            matrix_layout,
    char            job,
    char            eigsrc,
    char            initv,
    lapack_logical *            select,
    lapack_int            n,
    const float *            h,
    lapack_int            ldh,
    float *            wr,
    const float *            wi,
    float *            vl,
    lapack_int            ldvl,
    float *            vr,
    lapack_int            ldvr,
    lapack_int            mm,
    lapack_int *            m,
    float *            work,
    lapack_int *            ifaill,
    lapack_int *            ifailr
)
{
    if(_g_LAPACKE_shsein_work==NULL) {
        _g_LAPACKE_shsein_work = rindow_load_libopenblas_func("LAPACKE_shsein_work"); 
        if(_g_LAPACKE_shsein_work==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_shsein_work(
        matrix_layout,
        job,
        eigsrc,
        initv,
        select,
        n,
        h,
        ldh,
        wr,
        wi,
        vl,
        ldvl,
        vr,
        ldvr,
        mm,
        m,
        work,
        ifaill,
        ifailr    
    );
}
