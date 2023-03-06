SET OPENBLASPATH=C:\OpenBLAS\OpenBLAS-0.3.20-x64
cl -I%OPENBLASPATH%\include %OPENBLASPATH%\lib\libopenblas.lib /MD bit2.c
rem cl -IC:\OpenBLAS\OpenBLAS-0.3.7-x64\include C:\OpenBLAS\OpenBLAS-0.3.7-x64\lib\libopenblas.lib /MD bit2.c
rem cl -IC:\OpenBLAS\OpenBLAS-0.3.7-vc15-x64-static\include C:\OpenBLAS\OpenBLAS-0.3.7-vc15-x64-static\lib\openblas.lib /MD bit.c
