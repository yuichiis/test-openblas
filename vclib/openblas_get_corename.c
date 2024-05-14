#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "openblas_get_corename not found\n";
typedef char* (CALLBACK* PFNopenblas_get_corename)( /* openblas_get_corename */
    void            /*  */
);
static PFNopenblas_get_corename _g_openblas_get_corename = NULL;
char* openblas_get_corename(
    void            
)
{
    if(_g_openblas_get_corename==NULL) {
        _g_openblas_get_corename = rindow_load_libopenblas_func("openblas_get_corename"); 
        if(_g_openblas_get_corename==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_openblas_get_corename(
    
    );
}
