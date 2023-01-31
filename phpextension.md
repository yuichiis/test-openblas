>> sudo apt install build-essential autoconf automake libtool bison re2c
>> sudo apt install pkg-config
>> sudo apt install libopenblas-dev
>> sudo apt install php7.4-dev

>> php-7.x.x/ext$ ./ext_skel.php --ext rindow_openblas
>> Copying config scripts... done
>> Copying sources... done
>> Copying tests... done
>>
>> Success. The extension is now ready to be compiled into PHP. To do so, use the
>> following steps:
>> cd /path/to/php-src/ext/rindow_openblas
>> phpize
>> ####./buildconf
>> ./configure --enable-rindow_openblas
>> nmake
>>
>> Don't forget to run tests once the compilation is done:
>> nmake test TESTS=ext/rindow_openblas/tests
>>
>> Thank you for using PHP!


>> Build the OpenBLAS on MSVC with static library.
>> https://github.com/xianyi/OpenBLAS/wiki/How-to-use-OpenBLAS-in-Microsoft-Visual-Studio
>> >>>>> 1. Native (MSVC) ABI
>> Install Miniconda3 for 64 bits. And then follow the procedure described on the above page.
>>
>> Use OpenBLAS in MSVC
>> https://docs.microsoft.com/ja-jp/cpp/build/reference/md-mt-ld-use-run-time-library?view=vs-2019
>> cl -I..\OpenBLAS\build -I..\OpenBLAS\build\generated ..\OpenBLAS\build\lib\Release\openblas.lib /MD bit.c
>> bit.c
>> #include <stdio.h>
>> #include <cblas.h>
>> int main()
>> {
>>     float x1[10] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0 };
>>     printf("isamax=x[%d]=%f\n",(int)cblas_isamax(10, x1, 1),x1[(int)cblas_isamax(10, x1, 1)]);
>>     printf("isamin=x[%d]=%f\n",(int)cblas_isamin(10, x1, 1),x1[(int)cblas_isamin(10, x1, 1)]);
>> }

How to build
============

Build extension for Windows
---------------------------

Please refer to the following URL for details.

https://wiki.php.net/internals/windows/stepbystepbuild_sdk_2

### php sdk and devel-pack binaries for windows

- You must know that PHP 7.2,7.3 and 7.4 needs environment for the MSVC version vc15 (that means Visual Studio 2017). php-sdk releases 2.1.9 supports vc15.
- Download https://github.com/microsoft/php-sdk-binary-tools/releases/tag/php-sdk-2.1.9
- Extract to c:\php-sdk
- Download target dev-pack from https://windows.php.net/downloads/releases/
- Extract to /path/to/php-devel-pack-7.x.x-Win32-VC15-x64/

### start php-sdk for target PHP version

Open Visual Studio Command Prompt for VS for the target PHP version(see stepbystepbuild.)
Note that you must explicitly specify the version of vc15 for which php.exe was built.
The -vcvars_ver=14.16 means vc15.

```shell
C:\visual\studio\path>vcvars64 -vcvars_ver=14.16

C:\tmp>cd c:\php-sdk
C:\php-sdk>phpsdk-vXXX-xXX.bat
```

### Build

```shell
$ cd /path/to/here
$ /path/to/php-devel-pack-7.x.x-Win32-VC15-x64/phpize.bat
$ configure --enable-rindow_openblas --with-prefix=/path/to/php-installation-path --with-openblas=/path/to/OpenBLAS-libray-built-directory
$ nmake
$ nmake test
```


Install
=======

- Copy the php extension binary(.so or .dll or something) to the php/ext directory
  from here/arch/Releases_TS/php_rindow_openblas.(.so|.dll)
- Add the "extension=" entry to php.ini
