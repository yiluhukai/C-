
# 目标可以执行文件

main:main.o login.o
	gcc main.o login.o -o main
# 依赖的头文件和源文件
main.o:login.h main.c
	gcc -c main.c
login.o: login.c
	gcc -c login.c
