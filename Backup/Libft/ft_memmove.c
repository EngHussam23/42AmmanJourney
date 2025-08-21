/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:42:51 by halragga          #+#    #+#             */
/*   Updated: 2025/08/06 19:00:40 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *reverse_fill(char *dest, const char *src, size_t mvsize)
{
  	int i;
  
  	i = (int) mvsize - 1;
    while (i >= 0)
    {
        dest[i] = src[i];
        i--;
    }
    return (dest);
}

void    *ft_memmove(void *dest, const void *src, size_t mvsize)
{
    const char        *csrc;
    char            *cdest;
    size_t            i;

    csrc = (const char *)src;
    cdest = (char *)dest;
    i = 0;
    if (dest < src)
        return (ft_memcpy(cdest, csrc, mvsize));
    else if (dest > src)
        return (reverse_fill(cdest, csrc, mvsize));
    else
        return (cdest);
}

/*int    main(void)
{
    char    arr[10];
    int        i;

    arr[0] = 'W';
    arr[1] = 'o';
    arr[2] = 'r';
    arr[3] = 'l';
    arr[4] = 'd';
    arr[5] = '0';
    arr[6] = '0';
    arr[7] = '0';
    arr[8] = '0';
    arr[9] = '0';
    printf("Sending the array\n");
    ft_memmove(arr + 2, arr, 5);
    i = 0;
    while (i < 10)
    {
        printf("%c", arr[i]);
        i++;
    }
    printf("\n");
    return (0);
}*/
