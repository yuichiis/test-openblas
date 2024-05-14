#include <Windows.h>
#include <cblas.h>
#include "vclib.h"
static char msg_function_not_found[]  = "goto_set_num_threads not found\n";
typedef void (CALLBACK* PFNgoto_set_num_threads)( /* goto_set_num_threads */
    int            /* num_threads */
);
static PFNgoto_set_num_threads _g_goto_set_num_threads = NULL;
void goto_set_num_threads(
    int            num_threads
)
{
    if(_g_goto_set_num_threads==NULL) {
        _g_goto_set_num_threads = rindow_load_libopenblas_func("goto_set_num_threads"); 
        if(_g_goto_set_num_threads==NULL) {
            HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
            WriteConsole(hStdOut, msg_function_not_found, sizeof(msg_function_not_found), NULL, NULL);
            return;
        }
    }
    _g_goto_set_num_threads(
        num_threads    
    );
}
