# Get Next Line

**Get Next Line** is a project where I implemented a function to read a line from a file descriptor, one line at a time. This function adds a convenient tool to your C programming toolbox, while also teaching about static variables and memory management.

## Introduction

The purpose of this project is to create a function that reads and returns a line from a file descriptor. It provides practical experience with static variables and memory management in C. The function can be reused in various future projects.

The key function is:

```c
char *get_next_line(int fd);
```

This function reads from the file descriptor fd and returns the next line, including the newline character. It returns NULL when there is nothing more to read or if an error occurs.
Common Instructions

    The project must be written in C and follow the Norm coding standard.
    Your function must handle errors (segmentation faults, double free, etc.) and free all allocated memory to avoid leaks.
    You need to create a Makefile with the following rules:
        all: Compile the program.
        clean: Remove object files.
        fclean: Remove object files and the binary.
        re: Recompile everything.
    Your project will be evaluated based on the repository you submit. Only the code in the repository will be graded.
    The project must compile with the flags -Wall -Wextra -Werror and support the BUFFER_SIZE macro for flexible buffer size.

Mandatory Part

The goal of the mandatory part is to write the get_next_line() function. Here's what it entails:

    Function name: get_next_line
    Prototype: char *get_next_line(int fd);
    Turn in files: get_next_line.c, get_next_line_utils.c, get_next_line.h
    Parameters: fd - the file descriptor to read from.
    Return value:
        Returns the read line, including the newline character if present.
        Returns NULL when there is nothing more to read or an error occurs.

Your function should:

    Be able to read from both regular files and the standard input.
    Return each line separately, including the \n character.
    Handle different BUFFER_SIZE values (e.g., 1, 42, 9999).

Forbidden:

    The use of global variables.
    The use of lseek().
