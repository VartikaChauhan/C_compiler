all: compiler

compiler: parser.tab.o lex.yy.o ast.o symbol_table.o semantic.o main.o
	gcc -o compiler parser.tab.o lex.yy.o ast.o symbol_table.o semantic.o main.o -ll

parser.tab.c parser.tab.h: parser.y
	bison -d parser.y

lex.yy.c: lexer.l parser.tab.h
	flex lexer.l

ast.o: ast.c ast.h
	gcc -c ast.c

symbol_table.o: symbol_table.c symbol_table.h
	gcc -c symbol_table.c

semantic.o: semantic.c ast.h symbol_table.h
	gcc -c semantic.c

parser.tab.o: parser.tab.c
	gcc -c parser.tab.c

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

main.o: main.c
	gcc -c main.c

clean:
	rm -f compiler *.o parser.tab.* lex.yy.c
