#include "main.h"
int _printf(const char *format, ...)
{
    int counter = 0;
    va_list args;


    if (format == NULL)
    {
        return (-1);
    }
    va_start(args, format);
    while (*format)
    {
        if (*format != '%')
        {
            write(1, format, 1);
            counter++;
        }
        else
        {
            format++;
            if (*format == '\0')
            {
                break;
            }
            else if (*format == '%')
            {
                write(1, format, 1);
                counter++;
            }
            else if (*format == 'c')
            {
                char c = va_arg(args, int);
                write(1, &c, 1);
                counter++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                int leng = strlen(str);
                write(1, str, leng);
                counter += leng;
            }
            else if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                char num_buffer[32];
                int num_length = snprintf(num_buffer, sizeof(num_buffer), "%d", num);
                write(1, num_buffer, num_length);
                counter += num_length;
            }
        }
        format++;
    }
    va_end(args);
    return (counter);
}

