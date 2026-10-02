*This project has been created as part of the 42 curriculum by ibishak.*

## Description
Libft is the first project in the 42 curriculum. This project aims to assist student to gain understanding how standard functions in C libraries work by reconstructing them from scratch and learning how to use them effectively. 

### Functions to check and manipulate characters:
* ft_isalpha: Checks if c is an alphabetic character (a-z, A-Z). Returns non-zero if true, 0 otherwise.
* ft_isdigit: Checks if c is a digit (0-9). Returns non-zero if true, 0 otherwise.
* ft_isalnum: Checks if c is alphanumeric (letter or digit). Returns non-zero if true, 0 otherwise.
* ft_isascii: Checks if c is a valid ASCII character (0-127). Returns non-zero if true, 0 otherwise.
* ft_isprint: Checks if c is a printable character (space through '~'). Returns non-zero if true, 0 otherwise.
* ft_toupper: Converts a lowercase letter to uppercase. Returns the converted character, or c unchanged if it isn't lowercase.
* ft_tolower: Converts an uppercase letter to lowercase. Returns the converted character, or c unchanged if it isn't uppercase.

### Functions to manipulate strings:
* ft_strlen: Counts the length of the string s, not counting the null terminator. Returns the length.
* ft_strlcpy: Copies up to size-1 characters from src to dst, always null-terminating dst (if size > 0). Returns the total length of src (for truncation detection).
* ft_strlcat: Appends src to dst, ensuring the result is null-terminated and does not exceed size total bytes. Returns the total length of the string it tried to create.
* ft_strchr: Locates the first occurrence of ch (converted to char) in str, including the terminating null byte. Returns a pointer to it, or NULL if not found.
* ft_strrchr: Locates the last occurrence of ch (converted to char) in str, including the terminating null byte. Returns a pointer to it, or NULL if not found.
* ft_strncmp: Compares up to n characters of s1 and s2. Returns 0 if equal, or the difference between the first differing bytes (as unsigned char).
* ft_strnstr: Locates the first occurrence of the substring tiny within the first len bytes of big. Returns a pointer to it, or NULL if not found.
* ft_strdup: Allocates and returns a new string that is a duplicate of src. Returns NULL if allocation fails.
* ft_substr: Allocates and returns a new string that is a substring of s, starting at index start and up to len characters long. Returns NULL if allocation fails. 
* ft_strjoin: Allocates and returns a new string resulting from the concatenation of s1 and s2. Returns NULL if allocation fails.
* ft_strtrim: Allocates and returns a copy of s1 with any leading and trailing characters found in set removed. Returns NULL if allocation fails. 
* ft_split: Allocates and returns an array of strings obtained by splitting s using the delimiter character c. The array is NULL-terminated. Returns NULL if allocation fails.
* ft_strmapi: Allocates and returns a new string applying function f to each character of s, passing its index. Returns NULL if allocation fails.
* ft_striteri: Applies function f to each character of s (in place), passing its index and a pointer to the character.

### Functions to manipulate memory:
* ft_bzero: Zeroes out the first n bytes of the memory area pointed to by s.
* ft_calloc: Allocates memory for an array of nmemb elements of size bytes each, and initializes all allocated memory to zero. Returns a pointer to the allocated memory, or NULL if nmemb * size overflows or allocation fails. 
* ft_memchr: Locates the first occurrence of c in the first n bytes of s. Returns a pointer to it, or NULL if not found.
* ft_memcmp: Compares the first n bytes of str1 and str2. Returns 0 if equal, or the difference between the first differing bytes.
* ft_memcpy: Copies n bytes from src to dst. Behavior is undefined if the memory areas overlap. Returns dst.
* ft_memmove: Copies n bytes from src to dst, safely handling overlapping memory areas. Returns dst.
* ft_memset: Fills the first n bytes of the memory area pointed to by ptr with the constant byte value. Returns ptr. 

### Functions for numbers:
* ft_atoi: Converts the initial portion of str to an int, skipping leading whitespace and handling an optional sign. Returns the converted value. 
* ft_itoa: Allocates and returns a string representation of the integer n. Returns NULL if allocation fails.

### Functions to write to a file descriptor:
* ft_putchar_fd: Writes the character c to the file descriptor fd.
* ft_putstr_fd: Writes the string s to the file descriptor fd.
* ft_putendl_fd: Writes the string s followed by a newline to the file descriptor fd.
* ft_putnbr_fd: Writes the integer n to the file descriptor fd.

### Functions to manipulate linked lists:
* ft_lstnew: Allocates and returns a new list node (t_list) with content set to the given content and next set to NULL. Returns NULL if allocation fails.
* ft_lstadd_front: Inserts the node new at the beginning of the list lst.
* ft_lstsize: Counts and returns the number of nodes in the list lst. 
* ft_lstlast: Returns the last node of the list lst, or NULL if lst is empty.
* ft_lstadd_back: Inserts the node new at the end of the list lst. If lst is empty, new becomes the first element.
* ft_lstdelone: Frees the memory of a single list node's content (using del) and the node itself, without touching the rest of the list.
* ft_lstclear: Deletes and frees every node of the list lst, including the content of each node using del, and sets lst to NULL.
* ft_lstiter: Applies function f to the content of each node in the list lst, in order.
* ft_lstmap: Creates a new list resulting from applying function f to the content of each node of lst; on failure, frees any created nodes using del. Returns the new list, or NULL on allocation failure.

## Instructions

### Compilation
```
make        # Build libft.a
make clean  # Remove object files
make fclean # Remove object files and libft.a
make re     # Rebuild library
```
### Using the library

Include the header file:
```
#include "libft.h"
```
Compile program with library:
```
#cc main.c libft.a
```

## Resources

* Linux Manual Pages (man pages)
* https://man.freebsd.org/cgi/man.cgi 
* https://youtu.be/R9PTBwOzceo?si=i0nBKgZGPjfJ0-eO 
* https://man7.org/linux/man-pages/
* https://swarnakar-ani24.medium.com/a-noobs-guide-to-using-make-and-writing-makefile-f718135d816b
* AI assistance (Claude) was used during this project for:
- Debugging logic errors
- Reviewing code for correctness against standard library behavior
- Style/readability suggestions (Norm compliance, variable naming)

All code was written, tested, and understood by me. AI was used as a 
learning aid to catch bugs and explain *why* they were bugs — not to 
generate solutions I didn't understand or verify myself. 
