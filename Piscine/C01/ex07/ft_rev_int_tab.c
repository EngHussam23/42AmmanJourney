#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size);

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	i;
	int	index;

	temp = 0;
	i = 0;
	index = size - 1;
	while (i < index)
	{
		temp = tab[i];
		tab[i] = tab[index];
		tab[index] = temp;
		/*
		 * 0 1 2 3 4
		 * i = 0
		 * ind = 4
		 * i++
		 * ind--
		 * i = 1
		 * ind = 3
		 * ++
		 * --
		 * 2
		 * 2
		*/
		i++;
		index--;
	}
}

int	main(void)
{
	int	arr[5];
	int	size;

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;
	size = 0;
	while (arr[size] != '\0')
	{
		size++;
	}
	ft_rev_int_tab(arr, size);
	size = 0;
	while (arr[size] != '\0')
	{
                printf("%d\n", arr[size]);
		size++;
        }
	return(0);
}
