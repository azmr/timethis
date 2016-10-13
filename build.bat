@echo off

set CommonCompilerFlags=-nologo -MTd -fp:fast -Gm- -GR- -EHa- -Ox -Oi -WX -W4 -FC

IF NOT EXIST E:\Documents\Coding\C\build mkdir E:\Documents\Coding\C\build
pushd E:\Documents\Coding\C\build

call E:\Documents\Coding\C\shell64.bat

cl %CommonCompilerFlags% E:\Documents\Coding\C\timethis\timethis.c -Fmtimethis.map /link -incremental:no -opt:ref -PDB:timethis_%random%.pdb

popd


REM Flag Meanings:
REM ==============
REM
REM -nologo	- no Microsoft logo at the beginning of compilation
REM -Od		- no optimisation of code at all
REM -Ox		- full optimisation
REM -Oi		- use intrinsic version of function if exists
REM -Z7		- compatible debug info for debugger (replaced -Zi)
REM -GR-	- turn off runtime type info (C++)
REM -EHa-	- turn off exception handling (C++)
REM -W4		- 4th level of warnings
REM -WX 	- treat warnings as errors
REM -wd#### - remove warning ####
REM -D#####	- #define #### (=1)
REM -Gm-	- turn off 'minimal rebuild' - no incremental build
REM -Fm####	- provides location for compiler to put a .map file
REM -P		- output precompiled file to filename.i
REM
REM -MTd	- use (d => debug version of) static CRT library - needed for running on XP
REM /link -subsystem:windows,5.1 - ONLY FOR 32-BIT BUILDS!!! - needed for running on XP

REM Warnings Removed:
REM =================
REM
REM C4201: nonstandard extension used: nameless struct/union
REM C4100: unreferenced formal parameter
REM C4189: local variable is initialized but not referenced
REM C4204: nonstandard extension used: non-constant aggregate initializer
