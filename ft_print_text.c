/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_print_text.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: pnanna <pnanna@student.42bangkok.com>     #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/22 15:46:17 by pnanna           #+#    #+#              */
/*   Updated: 2026/11/22 15:46:17 by pnanna          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	count;

	if (!str)
		str = "(null)";
	count = 0;
	while (*str)
	{
		if (ft_putchar(*str) < 0)
			return (-1);
		count++;
		str++;
	}
	return (count);
}
// #include <stdio.h>

// int	main(void)
// {
// 	int	result;
//     result = ft_putchar('A');
// 	//result = ft_putchar('\n');
//     printf("\nreturn = %d\n", result);

//     fflush(stdout);

//     // Test return -1
//     // close(1);
//     // result = ft_putchar('B');
//     // fprintf(stderr, "return = %d\n", result);
// 	return (0);
// }

// int main(void)
// {
//     int result;

//     // Test 1: Normal string
//     result = ft_putstr("Hello");
//     printf("\nreturn = %d\n", result);

//     // Test 2: Empty string
//     result = ft_putstr("");
//     printf("return = %d\n", result);

//     // Test 3: NULL
//     result = ft_putstr(NULL);
//     printf("\nreturn = %d\n", result);

//     // Test 4: Error
//     fflush(stdout);
//     close(1);

//     result = ft_putstr("Hello");
//     fprintf(stderr, "return = %d\n", result);

//     return (0);
// }
