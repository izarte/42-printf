/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:05:42 by izarate-          #+#    #+#             */
/*   Updated: 2023/03/08 14:41:51 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_content(char c, va_list args, int *printed);

int	ft_printf(const char *content, ...)
{
	va_list	args;
	int		printed;
	int		i;

	if (!content)
		return (0);
	va_start(args, content);
	printed = 0;
	i = 0;
	while (content[i])
	{
		while (content[i] && content[i] != '%')
		{
			write(1, &(content[i]), 1);
			i++;
			printed++;
		}
		if (content[i])
		{
			i++;
			print_content(content[i], args, &printed);
			i++;
		}
	}
	return (printed);
}

static void	print_content(char c, va_list args, int *printed)
{
	char	c_arg;

	if (c == 'c')
	{
		c_arg = (char) va_arg(args, int);
		*printed += print_str(&c_arg);
	}
	if (c == 's')
		*printed += print_str(va_arg(args, char *));
	if (c == 'p')
		*printed += print_pointer(va_arg(args, unsigned long));
	if (c == 'x')
		*printed += print_hexa(va_arg(args, unsigned long), 0);
	if (c == 'X')
		*printed += print_hexa(va_arg(args, unsigned long), 1);
	if (c == 'i' || c == 'd')
		*printed += print_int(va_arg(args, int));
}
