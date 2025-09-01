#include <unistd.h>

int **ft_table_malloc(void)
{
    int **table;
    int i;

    i = 0;
    table = malloc(sizeof(int *) * 4);
    while (i < 4)
    {
        table[i] = malloc(sizeof(int) * 4);
        i++;
    }
    return (table);
}