#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_srotg not found\n";
typedef void (CALLBACK* PFNcblas_srotg)( /* cblas_srotg */
    float *            /* a */,
    float *            /* b */,
    float *            /* c */,
    float *            /* s */
);
static PFNcblas_srotg _g_cblas_srotg = NULL;
void cblas_srotg(
    float *            a,
    float *            b,
    float *            c,
    float *            s
)
{
    if(_g_cblas_srotg==NULL) {
        _g_cblas_srotg = rindow_load_libopenblas_func("cblas_srotg"); 
        if(_g_cblas_srotg==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_srotg(
        a,
        b,
        c,
        s    
    );
}
