#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_simatcopy not found\n";
typedef void (CALLBACK* PFNcblas_simatcopy)( /* cblas_simatcopy */
    OPENBLAS_CONST enum CBLAS_ORDER            /* CORDER */,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            /* CTRANS */,
    OPENBLAS_CONST blasint            /* crows */,
    OPENBLAS_CONST blasint            /* ccols */,
    OPENBLAS_CONST float            /* calpha */,
    float *            /* a */,
    OPENBLAS_CONST blasint            /* clda */,
    OPENBLAS_CONST blasint            /* cldb */
);
static PFNcblas_simatcopy _g_cblas_simatcopy = NULL;
void cblas_simatcopy(
    OPENBLAS_CONST enum CBLAS_ORDER            CORDER,
    OPENBLAS_CONST enum CBLAS_TRANSPOSE            CTRANS,
    OPENBLAS_CONST blasint            crows,
    OPENBLAS_CONST blasint            ccols,
    OPENBLAS_CONST float            calpha,
    float *            a,
    OPENBLAS_CONST blasint            clda,
    OPENBLAS_CONST blasint            cldb
)
{
    if(_g_cblas_simatcopy==NULL) {
        _g_cblas_simatcopy = rindow_load_libopenblas_func("cblas_simatcopy"); 
        if(_g_cblas_simatcopy==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_simatcopy(
        CORDER,
        CTRANS,
        crows,
        ccols,
        calpha,
        a,
        clda,
        cldb    
    );
}
