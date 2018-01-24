#!/bin/sh

yacc -yd ./parser.y
lex ./scaner.l
cc lex.yy.c y.tab.c node.c symtab.c -ly -ll -g -o parse
