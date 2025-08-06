/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hussam <hussam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:53:37 by hussam            #+#    #+#             */
/*   Updated: 2025/06/17 18:09:58 by hussam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
	// Test the isalpha function with various characters
	char test_chars[] = {'a', 'Z', '1', '!', ' ', '\n', 'b', 'C', 'z'};
	printf("Array size using sizeof() function: %ld\n\n", sizeof(test_chars));
	for (unsigned long i = 0; i < sizeof(test_chars); i++)
	{
		if (isalpha(test_chars[i]))
			write(1, "isalpha\n", 8);
		else
			write(1, "not isalpha\n", 12);
	}
	return 0;
}