/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:15:19 by halragga          #+#    #+#             */
/*   Updated: 2025/01/11 10:25:00 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	**ft_table_malloc(void);

int	ft_atoi(char *str);

int	validate_input(int *clues);

void	process_input(char *str);

int	main(int argc, char *argv[])
{
	if (argc < 2)
		write(2, "Error: Missing arguments.\n", 26);
	else if (argc > 2)
		write(2, "Error: Too many arguments\n", 26);
	else
		process_input(argv[1]);
	return (0);
}
