/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izarate- <izarate-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:07:32 by izarate-          #+#    #+#             */
/*   Updated: 2023/03/08 14:35:56 by izarate-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h> 
# define HEXADECIMAL_UPPERCASE "0123456789ABCDEF"
# define HEXADECIMAL_LOWERCASE "0123456789abcdef"
# define DECIMAL "0123456789"

int		ft_printf(const char *format, ...);
int		print_str(char *str);
int		print_pointer(unsigned long n);
int		print_hexa(unsigned long n, int mayus);
int		print_int(int n);
void	print_ubase(unsigned long n, unsigned long base, int *i, int mayus);
void	print_base(int n, unsigned long base, int *i, int mayus);

#endif