#include <unistd.h>

void ft_print_numbers(void)
{
    int i;

    i = 48;
    while (i <= 57)
    {
        write(1, &i, 1);
        i++;
    }
}

// int main(void)
// {
//     ft_print_numbers();
//     return (0);
// }