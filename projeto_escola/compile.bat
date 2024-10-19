@echo off

echo.
echo [0;33mcompiling program.win.bin ...[0;0m

gcc interface_main.c interface_cadastro.c interface_relatorio.c ansi_escapes.c -o program.win.exe

echo [0;32mcompilation complete.[0;0m