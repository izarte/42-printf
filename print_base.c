/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:42:57 by izarate-          #+#    #+#             */
/*   Updated: 2023/03/08 14:42:57 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_ubase(unsigned long n, unsigned long base, int *i, int mayus)
{
	if (n > base)
	{
		print_ubase(n / base, base, i, mayus);
		print_ubase(n % base, base, i, mayus);
	}
	else
	{
		*i += 1;
		if (base == 10)
			write(1, &DECIMAL[n], 1);
		if (base == 16)
		{
			if (mayus)
				write(1, &HEXADECIMAL_UPPERCASE[n], 1);
			else
				write(1, &HEXADECIMAL_LOWERCASE[n], 1);
		}
	}
}

void	print_base(int n, unsigned long base, int *i, int mayus)
{
	if (n < 0)
	{
		*i += 1;
		write(1, "-", 1);
		if (n == -2147483648)
		{
			if (base == 16)
			{
				write(1, "80000000", 8);
				*i += 8;
			}
			if (base == 10)
			{
				write(1, "-2147483648", 11);
				*i += 11;
			}
			return ;
		}
		n *= -1;
	}
	print_ubase(n, base, i, mayus);
}
