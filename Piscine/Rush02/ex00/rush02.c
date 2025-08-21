/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_processing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 03:15:02 by halragga          #+#    #+#             */
/*   Updated: 2025/01/18 16:33:23 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdbool.h>

#include <fcntl.h>

#include <stdio.h>

void	input_processing(int argc, char **input);

void	search_nbr(void);

bool	validate(char *input);

bool	check_dict(char *dict_to_check);

bool	check_dict(char *dict_to_check)
{
	char	*dict_file;
	int		i;

	i = 0;
	dict_file = "numbers.dict";
	while (dict_file[i] != '\0')
	{
		if (dict_to_check[i] == dict_file[i])
			i++;
		else
			return (false);
	}
	return (true);
}

bool	validate(char *input)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] >= '0' && input[i] <= '9')
			i++;
		else
			return (false);
	}
	return (true);
}

void	search_nbr(void)
{
}

void	input_processing(int argc, char **input)
{
	if (argc == 2)
	{
		if (!validate(input[1]))
		{
			write(2, "Error! Invalid input.", 21);
			return ;
		}
		else
			write(1, "Valid input!", 12);
	}
	else
	{
		if (!check_dict(input[1]))
		{
			write(2, "Error! Invalid reference file...", 32);
			return ;
		}
		if (!validate(input[2]))
		{
			write(2, "Error! Invalid input.", 21);
			return ;
		}
		else
			write(1, "Valid input!", 12);
	}
}

/*Close the dict file*/
/*close(dict_fd);*/
/*i = 0;*/
/*Open the .dict file*/
/*dict_fd = open("numbers.dict", O_RDONLY);*/
/*Validate input*/
/*int	i;*/
