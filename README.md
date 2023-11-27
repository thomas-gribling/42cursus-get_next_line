<h1 align="center">
        📝 get_next_line
</h1>

<p align="center">
        <i>42 cursus - Rank 1</i><br>
        Final grade: <b>125/100</b>
</p>

# 📰 Subject
This project consists in coding a function, named `get_next_line`, that takes a file descriptor as parameter and returns the next line every time it's called.<br>
The bonus part of this project consists in making it work with multiple file descriptors at once.<br>
The function is prototyped as following:
```c
char  *get_next_line(int fd);
```
You must also be able to define a `BUFFER_SIZE` value while compiling, without affecting the output.

# 🖥️ Usage
This project doesn't ask for a Makefile, so in order to compile it, you have two ways.<br>
`gcc -Wall -Wextra -Werror get_next_line.c get_next_utils.c -D BUFFER_SIZE=XX` - Single file descriptor version.<br>
`gcc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c -D BUFFER_SIZE=XX` - Multiple file descriptors version.<br>

To use this function in your own projects, copy the 3 source files of the version you want to use (regular or bonus) and include the corresponding header file:
```c
#include <get_next_line.h>
```
```c
#include <get_next_line_bonus.h>
```
