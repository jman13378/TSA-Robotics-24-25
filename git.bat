@echo off
CALL :Callback


:Callback
echo Git Add - 1
echo Git Commit - 2
echo Git Push - 3
echo All - 4


set /p input= Type any input (1-4): 


set /p conf= "Type any input (y|n / Default:y): "
if (%conf%=="") SET /A conf="y"

if (%conf%=="y") CALL :Callback
if %input%==1 CALL :gitadd
if %input%==2 CALL :gitcommit
if %input%==3 CALL :gitpush
if %input%==4 CALL :gitadd


EXIT


:gitadd 
echo "Adding Files..."

echo "Done."

:gitcommit

:gitpush
:gitall

