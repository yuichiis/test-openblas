#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_shsein not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_shsein)( /* LAPACKE_shsein */
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
    lapack_int *            /* ifaill */,
    lapack_int *            /* ifailr */
);
static PFNLAPACKE_shsein _g_LAPACKE_shsein = NULL;
lapack_int LAPACKE_shsein(
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
    lapack_int *            ifaill,
    lapack_int *            ifailr
)
{
    if(_g_LAPACKE_shsein==NULL) {
        _g_LAPACKE_shsein = rindow_load_libopenblas_func("LAPACKE_shsein"); 
        if(_g_LAPACKE_shsein==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_shsein(
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
        ifaill,
        ifailr    
    );
}
