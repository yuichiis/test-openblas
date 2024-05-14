#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "openblas_set_num_threads_local not found\n";
typedef int (CALLBACK* PFNopenblas_set_num_threads_local)( /* openblas_set_num_threads_local */
    int            /* num_threads */
);
static PFNopenblas_set_num_threads_local _g_openblas_set_num_threads_local = NULL;
int openblas_set_num_threads_local(
    int            num_threads
)
{
    if(_g_openblas_set_num_threads_local==NULL) {
        _g_openblas_set_num_threads_local = rindow_load_libopenblas_func("openblas_set_num_threads_local"); 
        if(_g_openblas_set_num_threads_local==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return 0;
        }
    }
    return _g_openblas_set_num_threads_local(
        num_threads    
    );
}
