#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_sgeadd not found\n";
typedef void (CALLBACK* PFNcblas_sgeadd)( /* cblas_sgeadd */
    OPENBLAS_CONST enum CBLAS_ORDER            /* CORDER */,
    OPENBLAS_CONST blasint            /* crows */,
    OPENBLAS_CONST blasint            /* ccols */,
    OPENBLAS_CONST float            /* calpha */,
    float *            /* a */,
    OPENBLAS_CONST blasint            /* clda */,
    OPENBLAS_CONST float            /* cbeta */,
    float *            /* c */,
    OPENBLAS_CONST blasint            /* cldc */
);
static PFNcblas_sgeadd _g_cblas_sgeadd = NULL;
void cblas_sgeadd(
    OPENBLAS_CONST enum CBLAS_ORDER            CORDER,
    OPENBLAS_CONST blasint            crows,
    OPENBLAS_CONST blasint            ccols,
    OPENBLAS_CONST float            calpha,
    float *            a,
    OPENBLAS_CONST blasint            clda,
    OPENBLAS_CONST float            cbeta,
    float *            c,
    OPENBLAS_CONST blasint            cldc
)
{
    if(_g_cblas_sgeadd==NULL) {
        _g_cblas_sgeadd = rindow_load_libopenblas_func("cblas_sgeadd"); 
        if(_g_cblas_sgeadd==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_sgeadd(
        CORDER,
        crows,
        ccols,
        calpha,
        a,
        clda,
        cbeta,
        c,
        cldc    
    );
}
