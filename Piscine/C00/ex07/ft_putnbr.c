/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hussam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:53:57 by hussam            #+#    #+#             */
/*   Updated: 2025/01/26 17:54:00 by hussam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int nbr)
{
    char c;

    if (nbr == -2147483648)
    {
        write(1, "-2147483648", 11);
    }
    else if (nbr < 0)
    {
        write(1, "-", 1);
        ft_putnbr(nbr * -1);
    }
    else if (nbr > 0 && nbr <= 9)
    {
        c = nbr + '0';
        write(1, &c, 1);
    }
    else
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
}

/*
int main(void)
{
    ft_putnbr(2147483647);
}
*/
