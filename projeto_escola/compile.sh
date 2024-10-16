#! /usr/bin/bash

echo -e "\033[0;33m compiling code ... \033[0;0m"

gcc interface.c ansi_escapes.c -o program.lin.bin

echo -e "\033[0;32m compilation complete, program.lin.bin created. \033[0;0m"