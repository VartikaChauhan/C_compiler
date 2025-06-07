# Simple C Compiler Using Flex, Bison, and C


## Overview

This project is a mini C compiler built from scratch using Flex for lexical analysis, Bison for syntax parsing, and C for implementation. It features:
- **Lexical Analysis**
- **Syntax Parsing and AST Generation**
- **Symbol Table Management**
- **Type Checking and Undeclared Variable Detection**
- **Function Declaration and Call Validation**
- **AST Evaluation for Visualization**

## Requirements

- Flex
- Bison
- GCC (and build-essential)
- Make
- Git (optional, for version control)


## 📂 Project Structure

c_compiler/
├── lexer.l # Lexical analyzer (Flex)
├── parser.y # Grammar and parser (Bison)
├── main.c # Entry point of compiler
├── ast.c / ast.h # Abstract Syntax Tree structure
├── symbol_table.c/.h # Symbol table logic
├── Makefile # Automate the build process
└── README.md # Project documentation


For Ubuntu:
```bash
sudo apt update
sudo apt install flex bison gcc build-essential git -y
