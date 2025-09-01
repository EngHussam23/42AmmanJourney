#include <unistd.h>

void    process_input(char *str);

int     main(int ac, char **av)
{
    if (ac == 2)
    {
        process_input(av[1]);
    }
    else
    	write(1, "Usage: ./program \"col1up col2up ... row4right\"\n", 1);
    return (0);
}
