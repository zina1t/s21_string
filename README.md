# s21_string+

## Preamble

1942, late evening, Bletchley Park, Alan Turing's desk.

For almost a year, a group of the brightest mathematicians, linguists and crossword puzzle enthusiasts have been trying to solve the most difficult problem of deciphering the German Enigma cipher, whose codes change every day and the number of possible combinations is about two to the power of 64. The group often had to come up with different algorithms, and they even developed a special set of keywords and their syntax for ease of communication and logging, which is exactly like the well-known C language in our universe. What a remarkable coincidence! But there was a catch - the people at Bletchley Park had to remember the whole sequence of actions described in this language.

As you walk past Turing's desk, you notice a sheet of paper that says "For processing letters, punctuation marks, words and sentences".

"What is this, Alan?" you asked the thoughtful young man standing at the window.

"These are the functions that will make our lives easier! You know, cracking Enigma by brute force… I'd rather marry Joan than do that. So it seems we have to keep analysing texts, looking for patterns and coincidences. And so we're going to have to come up with different algorithms that are related to the processing of that very text and describe them. So we need a set of functions to help us do that. I'm working on them now."

"And you are doing this using our new tool for representing unified algorithms?"

"Yes, that is exactly what I am doing. Where else could we use these functions?" Having said that, Turing looked at you as if you were an idiot. You noticed that and decided to show off your knowledge of the question:

"You know I think we really need this. I just recently learnt this 'specific language of algorithm transfer'."

"Seriously?" Alan asked with some interest.

"Well, yes."

After a few seconds, Turing came to the logical conclusion of entrusting you with the job:

"Listen, do you want to do it yourself? Get some not-so-busy and get on with it. And I'll continue to work on my mechanical code-breaking machine.

After thinking about it for a few seconds, you decide it's a great idea:

"Yes, I'll do everything in the best possible way!"

## Chapter I

### 1.1. Introduction

In this project you will develop your own implementation of the string.h library in the C programming language with some additions (with your own implementation of the sprintf and sscanf functions). The string.h library is the main C library for string handling. As part of the project, you'll work on tasks involving string data and consolidate the structured approach.

## Chapter II

### 2.1. Information

The C programming language has a set of functions implementing operations on strings (character strings and byte strings) in its standard library. Various operations, such as copying, concatenation, tokenization and searching are supported. For character strings, the standard library uses the convention that strings are null-terminated: a string of n characters is represented as an array of n + 1 elements, the last of which is a "NULL" character.
The only support for strings in the programming language proper is that the compiler translates quoted string constants into null-terminated strings.

### string.h Types

| No. | Variable | Description |
| --- | -------- | ----------- |
| 1   | size_t   | This is the unsigned integral type and is the result of the sizeof keyword. |

### string.h Macro

| No. | Macro | Description |
| --- | ----- | ----------- |
| 1   | NULL  | This macro is the value of a null pointer constant. |

### string.h Functions

| No. | Function | Description |
| --- | -------- | ----------- |
| 1   | void *memchr(const void *str, int c, size_t n) | Searches for the first occurrence of the character c (an unsigned char) in the first n bytes of the string pointed to, by the argument str. |
| 2   | int memcmp(const void *str1, const void *str2, size_t n) | Compares the first n bytes of str1 and str2. |
| 3   | void *memcpy(void *dest, const void *src, size_t n) | Copies n characters from src to dest. |
| 4   | void *memset(void *str, int c, size_t n) | Copies the character c (an unsigned char) to the first n characters of the string pointed to, by the argument str. |
| 5   | char *strncat(char *dest, const char *src, size_t n) | Appends the string pointed to, by src to the end of the string pointed to, by dest up to n characters long. |
| 6   | char *strchr(const char *str, int c) | Searches for the first occurrence of the character c (an unsigned char) in the string pointed to, by the argument str. |
| 7   | int strncmp(const char *str1, const char *str2, size_t n) | Compares at most the first n bytes of str1 and str2. |
| 8   | char *strncpy(char *dest, const char *src, size_t n) | Copies up to n characters from the string pointed to, by src to dest. |
| 9   | size_t strcspn(const char *str1, const char *str2) | Calculates the length of the initial segment of str1 which consists entirely of characters not in str2. |
| 10  | char *strerror(int errnum) | Searches an internal array for the error number errnum and returns a pointer to an error message string. You need to declare macros containing arrays of error messages for mac and linux operating systems. Error descriptions are available in the original library. Checking the current OS is carried out using directives. |
| 11  | size_t strlen(const char *str) | Computes the length of the string str up to but not including the terminating null character. |
| 12  | char *strpbrk(const char *str1, const char *str2) | Finds the first character in the string str1 that matches any character specified in str2. |
| 13  | char *strrchr(const char *str, int c) | Searches for the last occurrence of the character c (an unsigned char) in the string pointed to by the argument str. |
| 14  | char *strstr(const char *haystack, const char *needle) | Finds the first occurrence of the entire string needle (not including the terminating null character) which appears in the string haystack. |
| 15  | char *strtok(char *str, const char *delim) | Breaks string str into a series of tokens separated by delim. |

### sprintf and sscanf

- `int sscanf(const char *str, const char *format, ...)` - reads formatted input from a string;
- `int sprintf(char *str, const char *format, ...)` - sends formatted output to a string pointed to, by str.

where:
- `str` − This is the C string that the function processes as its source to retrieve the data;
- `format` − This is the C string that contains one or more of the following items: Whitespace character, Non-whitespace character and Format specifiers. A format specifier for print functions follows this prototype: `%[flags][width][.precision][length]specifier`. A format specifier for scan functions follows this prototype: `%[*][width][length]specifier`.

### sprintf And sscanf Specifiers

| No. | Specifier | sprintf output | sscanf output |
| --- | --------- | -------------- | ------------- |
| 1   | c         | Character      | Character     |
| 2   | d         | Signed decimal integer | Signed decimal integer |
| 3   | i         | Signed decimal integer | Signed integer (may be decimal, octal or hexadecimal) |
| 4   | e         | Scientific notation (mantissa/exponent) using e character (the output of the numbers must match up to e-6) | Decimal floating point or scientific notation (mantissa/exponent) |
| 5   | E         | Scientific notation (mantissa/exponent) using E character | Decimal floating point or scientific notation (mantissa/exponent) |
| 6   | f         | Decimal floating point | Decimal floating point or scientific notation (mantissa/exponent) |
| 7   | g         | Uses the shortest representation of decimal floating point | Decimal floating point or scientific notation (mantissa/exponent) |
| 8   | G         | Uses the shortest representation of decimal floating point | Decimal floating point or scientific notation (mantissa/exponent) |
| 9   | o         | Unsigned octal | Unsigned octal |
| 10  | s         | String of characters | String of characters |
| 11  | u         | Unsigned decimal integer | Unsigned decimal integer |
| 12  | x         | Unsigned hexadecimal integer | Unsigned hexadecimal integer (any letters) |
| 13  | X         | Unsigned hexadecimal integer (capital letters) | Unsigned hexadecimal integer (any letters) |
| 14  | p         | Pointer address | Pointer address |
| 15  | n         | Number of characters printed until %n occurs | Number of characters scanned until %n occurs |
| 16  | %         | Character % | Character % |

### sprintf Flags

| No. | Flags | Description |
| --- | ----- | ----------- |
| 1   | -     | Left-justify within the given field width; Right justification is the default. |
| 2   | +     | Forces to precede the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign. |
| 3   | (space) | If no sign is going to be written, a blank space is inserted before the value. |
| 4   | #     | Used with o, x or X specifiers the value is preceded with 0, 0x or 0X respectively for values different than zero. |
| 5   | 0     | Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier). |

### sprintf Width

| No. | Width | Description |
| --- | ----- | ----------- |
| 1   | (number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger. |
| 2   | *     | The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. |

### sprintf Precision

| No. | Precision | Description |
| --- | --------- | ----------- |
| 1   | .number | For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For e, E and f specifiers: this is the number of digits to be printed after the decimal point. For g and G specifiers: This is the maximum number of significant digits to be printed. For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. If the period is specified without an explicit value for precision, 0 is assumed. |
| 2   | .*      | The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted. |

### sprintf Length

| No. | Length | Description |
| --- | ------ | ----------- |
| 1   | hh     | For integer types, causes printf to expect an int-sized integer argument which was promoted from a `char`. |
| 2   | h      | For integer types, causes printf to expect an int-sized integer argument which was promoted from a `short`. |
| 3   | l      | For integer types, causes printf to expect a `long`-sized integer argument. |
| 4   | ll     | For integer types, causes printf to expect a `long long`-sized integer argument. |
| 5   | L      | For floating point types, causes printf to expect a `long double` argument. |
| 6   | z      | For integer types, causes printf to expect a `size_t`-sized integer argument. |

## Chapter III

### 3.1. Part 1

You need to implement the following functions:
- `void *memchr(const void *str, int c, size_t n)`
- `int memcmp(const void *str1, const void *str2, size_t n)`
- `void *memcpy(void *dest, const void *src, size_t n)`
- `void *memset(void *str, int c, size_t n)`
- `char *strncat(char *dest, const char *src, size_t n)`
- `char *strchr(const char *str, int c)`
- `int strncmp(const char *str1, const char *str2, size_t n)`
- `char *strncpy(char *dest, const char *src, size_t n)`
- `size_t strcspn(const char *str1, const char *str2)`
- `char *strerror(int errnum)`
- `size_t strlen(const char *str)`
- `char *strpbrk(const char *str1, const char *str2)`
- `char *strrchr(const char *str, int c)`
- `char *strstr(const char *haystack, const char *needle)`
- `char *strtok(char *str, const char *delim)`

### 3.2. Part 2

You need to implement your own `sprintf` function.

### 3.3. Part 3

You need to implement your own `sscanf` function.

### 3.4. Part 4

You need to create a static library (archive) with the string+ functions implemented in Parts 1-3.

### 3.5. Part 5

You need to develop a full set of tests to cover all the string+ functions you have implemented. 

## Chapter IV

### 4.1. Implementation Details

- Your project must be developed using C.
- You must write your own test cases to validate the correctness of your implementation.
- Make sure your code follows good coding practices, such as meaningful variable names, proper indentation, and inline comments.
- Optimize for readability and maintainability.
- Document your code thoroughly, explaining the purpose of functions and any complex logic.
- Ensure your implementation is robust and can handle edge cases gracefully.
- Adhere to the provided function prototypes and specifications.
