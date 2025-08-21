/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:20:09 by halragga          #+#    #+#             */
/*   Updated: 2025/08/20 16:20:07 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*will this work:
while ((n/=10) > 0) count++;
and then
if (n > 1- ) count++;
*/

char	*malloc_and_fill(int count, int sign, long n)
{
	char	*str;

	if (n == 0)
		count++;
	str = (char *)malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count--] = '\0';
	while (count >= 0)
	{
		if (sign == -1 && count == 0)
			str[0] = '-';
		else
		{
			str[count] = (n % 10) + '0';
			n /= 10;
		}
		count--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		sign;
	int		count;
	int		temp;

	sign = 0;
	if (n >= 0)
		sign = 1;
	else
	{
		sign = -1;
		if (n == -2147483648)
			return (malloc_and_fill(11, sign, 2147483648));
		else
			n *= -1;
	}
	temp = n;
	count = 0;
	while (temp > 0)
	{
		temp /= 10;
		count++;
	}
	if (sign == -1)
		count++;
	return (malloc_and_fill(count, sign, n));
}

/*int	main(void)
{
	printf("%d\n", 12345%10);
}*/
