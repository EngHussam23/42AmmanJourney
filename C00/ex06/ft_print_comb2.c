#include <unistd.h>

void ft_print_comb2(void)
{
    char a;
    char b;
    char c;
    char d;

    a = '0';
    b = '1';
    c = '2';
    d = '3';
    while (a <= 54)
    {
        while (b <= 55)
        {
            if (b == a)
            {
                b++;
            }
            while (c <= 56)
            {
                if (c == b && c == a)
                {
                    c++;
                }
                while (d <= 57)
                {
                    if (d == c && d == b && d == a)
                    {
                        d++;
                    }
                    if (a == 54 && b == 55 && c == 56 && d == 57)
                    {
                        write(1, &a, 1);
                        write(1, &b, 1);
                        write(1, " ", 1);
                        write(1, &c, 1);
                        write(1, &d, 1);
                    }
                    else
                    {
                        write(1, &a, 1);
                        write(1, &b, 1);
                        write(1, " ", 1);
                        write(1, &c, 1);
                        write(1, &d, 1);
                        write(1, ", ", 2);
                    }
                    d++;
                }
                c++;
                d = '3';
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
//     ft_print_comb2();
// }