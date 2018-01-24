# Makefile for the test directory /home/ubuntu/yacc-test01/libtest16-1=for-practicing-gdb.
# 20151120

# export  LD_LIBRARY_PATH="/home/ubuntu/yacc-test01"

CURDIR=/home/ubuntu/yacc-test01

cleanup:
	rm *.o a.out *~  lex.yy.c yacctest-inherit.tab.c y.tab.c y.tab.h *.so *.a
	ls

# sudo apt-get install bison  <selected package>

obj yacc:	
	flex lextest-inherit.l 
	yacc --defines yacctest-inherit.y
	# cc lex.yy.c -ll -o lex.o
	cc y.tab.c -ly -ll

######


