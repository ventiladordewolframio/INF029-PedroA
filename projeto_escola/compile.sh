#!/usr/bin/bash

echo " "
echo -e "\033[0;33m compiling \"program.lin.bin\" ...\033[0;0m"

gcc interface_main.c interface_cadastro.c interface_relatorio.c ansi_escapes.c -o program.lin.bin

echo -e "\033[0;32m compilation complete. \033[0;0m"
echo ""
