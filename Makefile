# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -g

# Target binary
TARGET = compiler

# Sources and objects
OBJS = parser.tab.o lex.yy.o ast.o symbol_table.o semantic.o main.o

# Default rule
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ -ll

# Generate parser source and header
parser.tab.c parser.tab.h: parser.y
	bison -d parser.y

# Generate lexer source
lex.yy.c: lexer.l parser.tab.h
	flex lexer.l

# Compile object files
ast.o: ast.c ast.h
	$(CC) $(CFLAGS) -c $<

symbol_table.o: symbol_table.c symbol_table.h
	$(CC) $(CFLAGS) -c $<

semantic.o: semantic.c ast.h symbol_table.h semantic.h
	$(CC) $(CFLAGS) -c $<

parser.tab.o: parser.tab.c
	$(CC) $(CFLAGS) -c $<

lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -c $<

main.o: main.c
	$(CC) $(CFLAGS) -c $<

# Clean generated files
clean:
	rm -f $(TARGET) *.o parser.tab.* lex.yy.c

.PHONY: all clean

