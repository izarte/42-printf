/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:29:39 by izarate-          #+#    #+#             */
/*   Updated: 2023/03/08 14:35:19 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_str(char *str)
{
	int	size;

	size = ft_strlen(str);
	write(1, str, size);
	return (size);
}

int	print_pointer(unsigned long n)
{
	int	i;

	i = 2;
	write(1, "0x", 2);
	i += print_hexa(n, 0);
	return (i);
}

int	print_hexa(unsigned long n, int mayus)
{
	int	i;

	i = 0;
	print_ubase(n, 16, &i, mayus);
	return (i);
}

int	print_int(int n)
{
	int	i;

	i = 0;
	print_base(n, 10, &i, 0);
	return (i);
}
