SET OPENBLASPATH=C:\OpenBLAS\OpenBLAS-0.3.20-x64
cl -I%OPENBLASPATH%\include %OPENBLASPATH%\lib\libopenblas.lib /MD bit.c
rem cl -I%OPENBLASPATH%\include %OPENBLASPATH%\lib\libopenblas.lib /MD bit2.c
