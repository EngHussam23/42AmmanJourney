#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int ret1, ret2;

    // Basic string
    ret1 = ft_printf("Hello, %s!\n", "world");
    ret2 = printf("Hello, %s!\n", "world");
    printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

    // Integer
    ret1 = ft_printf("Number: %d\n", 42);
    ret2 = printf("Number: %d\n", 42);
    printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

    // Hexadecimal
    ret1 = ft_printf("Hex: %x\n", 255);
    ret2 = printf("Hex: %x\n", 255);
    printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

    // Pointer
    int x = 42;
    ret1 = ft_printf("Pointer: %p\n", &x);
    ret2 = printf("Pointer: %p\n", &x);
    printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

    // Character
    ret1 = ft_printf("Char: %c\n", 'A');
    ret2 = printf("Char: %c\n", 'A');
    printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

    // Percent sign
    ret1 = ft_printf("Percent: %%\n");
    ret2 = printf("Percent: %%\n");
    printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

    // Edge cases
    ret1 = ft_printf("Empty string: %s\n", "");
    ret2 = printf("Empty string: %s\n", "");
    printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

    ret1 = ft_printf("NULL string: %s\n", NULL);
    ret2 = printf("NULL string: %p\n", NULL);
    printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

    ret1 = ft_printf("INT_MIN: %d\n", -2147483648);
    ret2 = printf("INT_MIN: %ld\n", -2147483648);
    printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

    ret1 = ft_printf("INT_MAX: %d\n", 2147483647);
    ret2 = printf("INT_MAX: %d\n", 2147483647);
    printf("ft_printf returned: %d, printf returned: %d\n\n", ret1, ret2);

    ft_printf(NULL);
    // printf(NULL);

    return 0;
}