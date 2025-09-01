/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:26:48 by halragga          #+#    #+#             */
/*   Updated: 2025/08/05 19:52:14 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	ft_bzero(void *ptr, size_t size)
{
	size_t		i;
	char		*cptr;

	i = 0;
	cptr = ptr;
	while (i < size)
	{
		cptr[i] = '\0';
		i++;
	}
}

/*int	main(void)
{
	char	tst1[5];
	char	tst2[5];
	int		i;
	
	//Test 1
	tst1[0] = 's';
	tst1[1] = 'e';
	tst1[2] = 'w';
	tst1[3] = 'q';
	tst1[4] = 'r';
	//Test 2
	tst2[0] = 'a';
	tst2[1] = 'p';
	tst2[2] = 'f';
	tst2[3] = 'h';
	tst2[4] = 'j';
	bzero(tst1, 5);
	ft_bzero(tst2, 5);
	i = 0;
	while (i < 5)
	{
		printf("std = %c, usr = %c\n", tst1[i], tst2[i]);
		i++;
	}
	return (0);
}*/
