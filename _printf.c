#include <stdio.h>
#include <stdarg.h>

/**
* _printf - Prints formatted output to stdout
* @format: A string of characters that may include format specifiers
* Return: The number of characters printed to stdout
*/
int _printf(const char *format, ...)
{
    int printed_chars = 0;
    int int_arg;
    unsigned int uint_arg;
    char char_arg;
    char *str_arg;
    void *ptr_arg;
    char format_char;
    va_list args;
    va_start(args, format);


    while (*format != '\0')
    {
        if (*format == '%')
        {
            format_char = *(++format);
            switch (format_char)
            {
            case 'd':
            case 'i':
                int_arg = va_arg(args, int);
                printed_chars += printf("%d", int_arg);
                break;
            case 'u':
                uint_arg = va_arg(args, unsigned int);
                printed_chars += printf("%u", uint_arg);
                break;
            case 'o':
                uint_arg = va_arg(args, unsigned int);
                printed_chars += printf("%o", uint_arg);
                break;
            case 'x':
            case 'X':
                uint_arg = va_arg(args, unsigned int);
                printed_chars += printf("%x", uint_arg);
                break;
            case 'c':
                char_arg = (char)va_arg(args, int);
                printed_chars += printf("%c", char_arg);
                break;
            case 's':
                str_arg = va_arg(args, char *);
                printed_chars += printf("%s", str_arg);
                break;
            case 'p':
                ptr_arg = va_arg(args, void *);
                printed_chars += printf("%p", ptr_arg);
                break;
            case '%':
                putchar('%');
                printed_chars++;
                break;
            default:
                printf("%c", format_char);
                printed_chars += 2;
                break;
            }
            format++;
        }
        else
        {
            putchar(*format);
            printed_chars++;
            format++;
        }
    }

    va_end(args);
    return printed_chars;
}
