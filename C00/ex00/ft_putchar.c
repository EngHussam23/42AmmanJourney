#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
    write(1, "\n", 1);
}

// int main(int argc, char **argv)
// {
//     if (argc < 2)
//     {
//         write(2, "Error!\n", 7);
//         return 0;
//     }
//     ft_putchar(argv[1][0]);
// }