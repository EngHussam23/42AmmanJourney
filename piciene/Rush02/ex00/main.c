/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:34:31 by halragga          #+#    #+#             */
/*   Updated: 2025/01/18 15:08:35 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	input_processing(int argc, char **input);

int	main(int argc, char **argv)
{
	if (argc <= 3)
	{
		if (argc == 1)
			write(2, "Error!\n", 7);
		else if (argc == 2)
		{
			input_processing(argc, argv);
		}
		else if (argc == 3)
		{
			input_processing(argc, argv);
		}
	}
	else
	{
		write(2, "Too many arguments", 17);
	}
}
