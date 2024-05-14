#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_drotg not found\n";
typedef void (CALLBACK* PFNcblas_drotg)( /* cblas_drotg */
    double *            /* a */,
    double *            /* b */,
    double *            /* c */,
    double *            /* s */
);
static PFNcblas_drotg _g_cblas_drotg = NULL;
void cblas_drotg(
    double *            a,
    double *            b,
    double *            c,
    double *            s
)
{
    if(_g_cblas_drotg==NULL) {
        _g_cblas_drotg = rindow_load_libopenblas_func("cblas_drotg"); 
        if(_g_cblas_drotg==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_drotg(
        a,
        b,
        c,
        s    
    );
}
