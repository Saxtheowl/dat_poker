#!/bin/bash


cd other/XPokerEval/linux
make
if [ "$OS" = "Windows_NT" ]
then
./generate_table.exe
    exit
else
./generate_table
    exit
fi
