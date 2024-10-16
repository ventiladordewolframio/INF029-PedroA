@echo off

echo [0;33mcompiling code ...[0;0m

gcc interface.c ansi_escapes.c -o program.win.exe

echo [0;32mcompilation complete, program.win.exe created.[0;0m