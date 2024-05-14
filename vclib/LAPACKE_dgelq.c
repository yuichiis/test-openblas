#include <Windows.h>
#if _MSC_VER
#include <complex.h>
#define lapack_complex_float _Fcomplex
#define lapack_complex_double _Dcomplex
#endif
#include <lapacke.h>
#include "vclib.h"
static char msg_function_not_found[]  = "LAPACKE_dgelq not found\n";
typedef lapack_int (CALLBACK* PFNLAPACKE_dgelq)( /* LAPACKE_dgelq */
    int            /* matrix_layout */,
    lapack_int            /* m */,
    lapack_int            /* n */,
    double *            /* a */,
    lapack_int            /* lda */,
    double *            /* t */,
    lapack_int            /* tsize */
);
static PFNLAPACKE_dgelq _g_LAPACKE_dgelq = NULL;
lapack_int LAPACKE_dgelq(
    int            matrix_layout,
    lapack_int            m,
    lapack_int            n,
    double *            a,
    lapack_int            lda,
    double *            t,
    lapack_int            tsize
)
{
    if(_g_LAPACKE_dgelq==NULL) {
        _g_LAPACKE_dgelq = rindow_load_libopenblas_func("LAPACKE_dgelq"); 
        if(_g_LAPACKE_dgelq==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_LAPACKE_dgelq(
        matrix_layout,
        m,
        n,
        a,
        lda,
        t,
        tsize    
    );
}
