/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:05:42 by izarate-          #+#    #+#             */
/*   Updated: 2023/03/07 13:34:04 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include <stdio.h>

int	ft_strlen(const char *);
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

int	print_str(char *str)
{
	int	size;

	size = ft_strlen(str);
	// printf("%i\n", size);
	write(1, str, size);
	return (size);
}

void	print_base(unsigned long n, unsigned long base, int *i, int mayus)
{
	if (n > base)
	{
		print_base(n / 16, base, i, mayus);
		print_base(n % 16, base, i, mayus);
	}
	else
	{
		*i++;
		if (base == 10)
			write(1, &DECIMAL[n], 1);
		if (base == 16)
			if (mayus)
				write(1, &HEXADECIMAL_UPPERCASE[n], 1);
			else
				write(1, &HEXADECIMAL_LOWERCASE[n], 1);
	}
}

int	print_pointer(unsigned long p)
{
	int	i;

	i = 2;
	write(1, "0x", 2);
	print_base(p, 16, &i, 0);
	return (i);
}

static void	print_content(char c, va_list args, int *printed)
{
	char	c_arg;
	
	if (c == 'c')
	{
		c_arg =	(char) va_arg(args, int);
		*printed += print_str(&c_arg);
	}
	if (c == 's')
		*printed += print_str(va_arg(args, char *));
	if (c == 'p')
		*printed += print_pointer(va_arg(args, unsigned long));
	if (c == 'x')
		
	if (c == 'X')

}
