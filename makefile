# Makefile for BKX back tool
# Copyright (C) 2013 Wu Liwei
# Just use super user and make it. Do not edit.
#
# This Makefile is free software: you have unlimited permission
# to copy, distribute and modify it.

bkx:bkx.o error.o fileCheck.o help.o iox.o pathVary.o reply.o savex.o
	gcc bkx.o error.o fileCheck.o help.o iox.o pathVary.o reply.o savex.o -o bkx -lm
bkx.o:./src/bkx.c
	gcc -c ./src/bkx.c
error.o:./src/error.c
	gcc -c ./src/error.c
fileCheck.o:./src/fileCheck.c
	gcc -c ./src/fileCheck.c
help.o:./src/help.c
	gcc -c ./src/help.c
iox.o:./src/iox.c
	gcc -c ./src/iox.c
pathVary.o:./src/pathVary.c
	gcc -c ./src/pathVary.c
reply.o:./src/reply.c
	gcc -w -c ./src/reply.c
savex.o:./src/savex.c
	gcc -w -c ./src/savex.c
install:
	cp ./bkx /usr/bin
	mkdir /usr/local/share/bkx_backup_directory
clean:
	rm -f ./*.o
remove:
	rm -f /usr/bin/bkx
	rm -rf /usr/local/share/bkx_backup_directory
