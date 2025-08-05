/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:08:52 by halragga          #+#    #+#             */
/*   Updated: 2025/08/04 18:51:58 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_isdigit(int d);

int	ft_isdigit(int d)
{
	if (d >= 48 && d <= 57)
		return (2048);
	else
		return (0);
}

/*
int	main(int argc, char *argv[])
{
	if (argc > 2)
		printf("Too many arguments...");
	else if (argc < 2)
		printf("Missing argument...");
	else
		printf("1 = Digit\n0 = Non Digit\n\n\nResult: %d\n", ft_isdigit(argv[1][0]));
	return (0);
}
*/
