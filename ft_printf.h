/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnanna <pnanna@student.42bangkok.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 16:10:24 by pnanna            #+#    #+#             */
/*   Updated: 2026/11/22 16:10:26 by pnanna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_putbase(uintptr_t n, const char *digits, unsigned int base);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_puthex(uintptr_t n, const char *digits);
int	ft_putptr(void *ptr);

#endif
