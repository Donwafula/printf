#include "main.h"

int main(void)
{
     _printf("Character: %c\n", 'A');
     _printf("String: %s\n", "Hello, world!");
     _printf("Percent sign: %%\n");
     _printf("Integer: %d\n", 12345);
     _printf("%S\n", "Best\nSchool");
     int num = 10;
     _printf("Address of num: %p\n", &num);

     return (0);
}
