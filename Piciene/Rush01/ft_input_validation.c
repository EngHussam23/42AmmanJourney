#include <unistd.h>
#include <stdlib.h>

int	**ft_table_malloc(void);

void	ft_free(int **table, int size);

void	ft_fill_board(int **table, int size, int *clues);

int	ft_atoi(char *str)
{
	int	num;

	num = 0;
	while (*str >= '1' && *str <= '4')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num);
}

int	validate_input(int *clues)
{
	int	i;

	i = 0;
	while (i < 4)// Check columns
	{
		int	col_up;
		int	col_down;
		
		col_up = clues[i];
		col_down = clues[i + 4];
		if (col_up + col_down > 5)
			return (0); // Invalid
		if (col_up == 1 && col_down == 1)
			return (0); // Invalid
		i++;
	}
	i = 8;// Check rows
	while (i < 12)
	{
		int row_left = clues[i];
		int row_right = clues[i + 4];
		if (row_left + row_right > 5)
		return (0); // Invalid
		if (row_left == 1 && row_right == 1)
		return (0); // Invalid
		i++;
    	}
    	return (1); // Valid
}

void	process_input(char *str)
{
	int	clues[16];
	int	i;
	int	**table	;

	i = 0;
	while (*str)
	{
		while (*str == ' ')
			str++;
		if (*str >= '1' && *str <= '4')
		{
			clues[i++] = ft_atoi(str);
			//while (*str >= '1' && *str <= '4')
			//	str++;
		}
		else
			str++;
    	}
	if (i != 16 || !validate_input(clues))
	{
		write(2, "Invalid input\n", 14);
		return;
	}
	else
	{
		write(1, "Valid input!\n", 13);
		table = ft_table_malloc();
		//ft_fill_board(table, 4, clues);
		ft_free(table, 4);
	}
}
