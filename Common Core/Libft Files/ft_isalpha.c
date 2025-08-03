/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 15:45:30 by halragga          #+#    #+#             */
/*   Updated: 2025/08/03 15:58:12 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	check_char(char c);

int	check_char(char c)
{
	//printf("Checking...\n");
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

int	ft_isalpha(char *input)
{
	int	i;
	int	result;

	i = 0;
	while (input[i] != '\0')
	{
		//printf("Looping...");
		if (check_char(input[i]) == 0)
			result = 0;
		else
			result = 1;
		if (result == 0)
			return (result);
		i++;
	}
	return (1);
}

/*
int	main(int argc, char *argv[])
{
	if (argc > 2)
		printf("Too many arguments...");
	else if (argc < 2)
		printf("Missing arguments...");
	else
	{
		printf("Checking...\n");
		printf("Done.\n");
		printf("Result: %d\n", ft_isalpha(argv[1]));
	}
	return (0);
}
*/
