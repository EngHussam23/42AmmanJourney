/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halragga <halragga@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:59:45 by halragga          #+#    #+#             */
/*   Updated: 2025/09/17 16:50:17 by halragga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "ft_get_next_line.h"

int    main(void)
{
    int    fd;

    fd = open("file2.txt", O_CREAT | O_RDWR);
    write(fd, "123\n456\n789\n-0-", 15);
    printf("the content of 'file.txt' is: %s\n", ft_get_next_line(fd));
    return (0);
}
