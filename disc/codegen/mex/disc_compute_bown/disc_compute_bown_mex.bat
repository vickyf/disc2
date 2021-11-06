@echo off
call setEnv.bat
"G:\Others\MATLAB\R2020\toolbox\shared\coder\ninja\win64\ninja.exe" -t compdb cc cxx cudac > compile_commands.json
"G:\Others\MATLAB\R2020\toolbox\shared\coder\ninja\win64\ninja.exe" -v %*
