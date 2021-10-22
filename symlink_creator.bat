::  ================================================================== ::
::  ========================  Puvox.Software  ======================== ::
::  ================================================================== ::
::  ============== Symlink Creator with Drag&Drop v1.3 =============== ::
::  This script makes a symlink of any files/folders  ( instructions at:  https://goo.gl/8vYCDT  ) 
::  ================================================================== ::
::  ================================================================== ::

@echo off
setlocal enableextensions enabledelayedexpansion

if "%~1"=="" ( mshta "javascript:alert('You should drag desired files onto this');close();" && exit )

set /P inputed_target_dir= Path to folder, wherein the symlink will be created:
set inputed_target_dir=%inputed_target_dir%\
set type=0

for %%a in (%*) do  (

rem  in PARENTHESIS we use ! instead % for set-ed variables  (read more: https://superuser.com/a/78509/249349 )
set original_path=%%a
set original_path_quoted=!original_path!
rem  Make it quoted (if it's not already quoted)
set original_path_quoted|find """" >nul || set original_path_quoted="!original_path!"

set isDirectory=no
:: if directory
FOR %%i IN (!original_path_quoted!) DO IF EXIST %%~si\NUL (
	set isDirectory=yes
	for /D %%i in (!original_path_quoted!) do SET original_drive=%%~di
	for /D %%i in (!original_path_quoted!) do SET original_dir=!original_drive!%%~pi
	for /f "delims=" %%i in (!original_path_quoted!) do SET original_basename=%%~ni
)

:: if file
FOR %%i IN (!original_path_quoted!) DO IF NOT EXIST %%~si\NUL (
	set isDirectory=no
	for /f "delims=" %%i in (!original_path_quoted!) do SET original_drive=%%~di
	for /f "delims=" %%i in (!original_path_quoted!) do SET original_dir=!original_drive!%%~pi
	for /f "delims=" %%i in (!original_path_quoted!) do SET original_basenameWithExt=%%~nxi
)


for /D %%i in ("%inputed_target_dir%") do SET target_drive=%%~di
for /D %%i in ("%inputed_target_dir%") do SET target_dir=!target_drive!%%~pi
  
set isSameDrive=1
IF /I "!original_drive!"=="!target_drive!" (  set isSameDrive=2 )

:: if same ditectories, then use prefix name
set prefix=
IF /I "!original_dir!"=="!target_dir!" ( set prefix=_symlinked_ )

if !type! LSS 1 (
	rem ::   If same drives, then allow user to choose HARD method. Otherwise, only SOFT can be used
	set type=2

	rem ::   DONT USE   "!isSameDrive!"=="yes"  comaprison, as it has issue  
	if /i !isSameDrive! GTR 2 ( set /P type= Seems source and Destinaton drives are same, so you have an opportunity to create HARD-SYMLINK [press 1], otherwise press ENTER and the default SOFT-SYMLINK will be created : )
)

:: if directory
if !isDirectory!==yes (
	FOR %%i IN (!original_path_quoted!) DO IF EXIST %%~si\NUL (
		IF "!type!"=="1" ( 
		  mklink /J "!target_dir!\!prefix!!original_basename!" !original_path_quoted!
		) ELSE ( 
		  mklink /D "!target_dir!\!prefix!!original_basename!" !original_path_quoted!
		)
	)
)

:: if file
if !isDirectory!==no (
	FOR %%i IN (!original_path_quoted!) DO IF NOT EXIST %%~si\NUL (
		IF "!type!"=="1" ( 
		  mklink /H "!target_dir!\!prefix!!original_basenameWithExt!" !original_path_quoted!
		) ELSE ( 
		  mklink "!target_dir!\!prefix!!original_basenameWithExt!" !original_path_quoted!
		)
	)
)


)
:: FOR loop


:: mshta "javascript:alert('error: creating Hard-Symlink for different drives has failed');close();"
mshta "javascript:alert('Finished');close();"
endlocal