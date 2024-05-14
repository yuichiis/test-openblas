#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "cblas_drotmg not found\n";
typedef void (CALLBACK* PFNcblas_drotmg)( /* cblas_drotmg */
    double *            /* d1 */,
    double *            /* d2 */,
    double *            /* b1 */,
    OPENBLAS_CONST double            /* b2 */,
    double *            /* P */
);
static PFNcblas_drotmg _g_cblas_drotmg = NULL;
void cblas_drotmg(
    double *            d1,
    double *            d2,
    double *            b1,
    OPENBLAS_CONST double            b2,
    double *            P
)
{
    if(_g_cblas_drotmg==NULL) {
        _g_cblas_drotmg = rindow_load_libopenblas_func("cblas_drotmg"); 
        if(_g_cblas_drotmg==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_cblas_drotmg(
        d1,
        d2,
        b1,
        b2,
        P    
    );
}
