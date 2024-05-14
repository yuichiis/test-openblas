#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "openblas_get_num_procs not found\n";
typedef int (CALLBACK* PFNopenblas_get_num_procs)( /* openblas_get_num_procs */
    void            /*  */
);
static PFNopenblas_get_num_procs _g_openblas_get_num_procs = NULL;
int openblas_get_num_procs(
    void            
)
{
    if(_g_openblas_get_num_procs==NULL) {
        _g_openblas_get_num_procs = rindow_load_libopenblas_func("openblas_get_num_procs"); 
        if(_g_openblas_get_num_procs==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_openblas_get_num_procs(
    
    );
}
