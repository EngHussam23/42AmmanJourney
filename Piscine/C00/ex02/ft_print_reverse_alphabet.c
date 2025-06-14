/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hussam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:51:01 by hussam            #+#    #+#             */
/*   Updated: 2025/01/26 17:51:03 by hussam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_reverse_alphabet(void)
{
    int i;

    i = 122;
    while (i >= 97)
    {
        write(1, &i, 1);
        i--;
    }
}

// int main(void)
// {
//     ft_print_reverse_alphabet();
//     return (0);
// }
