@echo off

@if not "%MINGW_ROOT%" == "" (@set "PATH=%PATH%;%MINGW_ROOT%")

cd .

if "%1"=="" ("G:\Others\MATLAB\R2020\bin\win64\gmake"  -f disc_compute_bown_rtw.mk all) else ("G:\Others\MATLAB\R2020\bin\win64\gmake"  -f disc_compute_bown_rtw.mk %1)
@if errorlevel 1 goto error_exit

exit 0

:error_exit
echo The make command returned an error of %errorlevel%
exit 1