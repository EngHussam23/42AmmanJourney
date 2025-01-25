#include <unistd.h>

void ft_print_comb(void)
{
    char a;
    char b;
    char c;

    a = '0';
    b = '1';
    c = '2';
    while (a <= 55)
    {
        while (b <= 56)
        {
            if (b == a)
            {
                b++;
            }
            while (c <= 57)
            {
                if (c == b && c == a)
                {
                    c++;
                }
                if (a == 55 && b == 56 && c == 57)
                {
                    write(1, &a, 1);
                    write(1, &b, 1);
                    write(1, &c, 1);
                }
                else
                {
                    write(1, &a, 1);
                    write(1, &b, 1);
                    write(1, &c, 1);
                    write(1, ", ", 2);
                }
                c++;
            }
            b++;
            c = '2';
        }
        a++;
        b = '1';
    }
}

// int main(void)
// {
//     ft_print_comb();
// }