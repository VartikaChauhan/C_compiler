# 🚀 Simple C Compiler Using Flex, Bison, and C

## 📝 Overview

This project is a **fully functional mini C compiler** developed from scratch using:

- **Flex** for lexical analysis
- **Bison** for syntax parsing
- **C** for compiler logic and semantic analysis

It is designed to parse a subset of the C language and includes a full pipeline from tokenization to semantic analysis and AST evaluation.

---

## 🔧 Features

- ✅ **Lexical Analysis** using Flex
- ✅ **Syntax Parsing** with Bison (LALR parser)
- ✅ **Abstract Syntax Tree (AST)** construction and traversal
- ✅ **Symbol Table Management** for scoped variables and function identifiers
- ✅ **Type Checking** for expressions, assignments, and operations
- ✅ **Undeclared Variable Detection**
- ✅ **Function Declaration & Call Validation**
- ✅ **Error Handling** with informative messages
- ✅ **AST Evaluation & Visualization Support**


---

## ⚙️ Requirements

Install the following dependencies:

- [Flex](https://github.com/westes/flex)
- [Bison](https://www.gnu.org/software/bison/)
- [GCC](https://gcc.gnu.org/)
- Make
- Git (optional, for version control)


## 📸 Sample Compilation Snapshot

![Compilation Snapshot](C_compiler%20snap.jpeg)



### For Ubuntu/Debian-based systems:

```bash
sudo apt update
sudo apt install flex bison gcc build-essential git -y

# Build the Compiler
make

#Run the Compiler
./compiler test.c


#This will parse test.c and perform lexical, syntax, and semantic analysis.










