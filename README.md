# pipex

A program that simulates the pipe operator (`|`) in shell, implementing pipe-like behavior between processes. This project is part of the 42 school curriculum.

## Description

The pipex program takes 4 arguments and executes a pipe operation similar to the shell command:

## Features

- Handles multiple pipes and commands
- Supports absolute and relative paths
- Error handling for invalid commands and files
- Memory management
- Uses standard Unix system calls:
  - pipe
  - fork
  - execve
  - dup2
  - wait

## Requirements

- GCC compiler
- Make
- Unix-based operating system

### Compilation

To compile the program, use the following command:

```bash
make
```

### Running the Program

To run the program, use the following command:

```bash
./pipex <file1> <cmd1> <cmd2> <file2>
```
