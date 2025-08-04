/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 15:45:30 by halragga          #+#    #+#             */
/*   Updated: 2025/08/04 17:06:16 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

int	ft_isalpha(int c);

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	else
		return (0);
}

// int	main(int argc, char *argv[])
// {
// 	if (argc > 2)
// 		printf("Too many arguments...\n");
// 	else if (argc < 2)
// 		printf("Missing arguments...\n");
// 	else
// 	{
// 		printf("Checking...\n");
// 		printf("Done.\n");
// 		printf("Result: %d\n", ft_isalpha(argv[1][0]));
// 	}
// 	return (0);
// }
