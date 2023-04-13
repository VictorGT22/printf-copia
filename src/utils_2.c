/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:05:42 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/16 16:49:15 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include/ft_printf.h"

void	write_exp(int exp)
{
	if (exp < 0)
	{
		write(1, "-", 1);
		exp *= -1;
	}
	else
		write(1, "+", 1);
	if (exp > -10 && exp < 10)
		write(1, "0", 1);
	ft_putnbr_base(exp, "0123456789");
}

int	func_a(va_list list, t_list *info)
{
	double	num;
	long	unit_part;
	double	deci_part;

	num = va_arg(list, double);
	unit_part = num;
	deci_part = num - unit_part;
	print_decimal_part(unit_part, deci_part, info, "0123456789abcdef");
	return (1);
}

int	func_upper_a(va_list list, t_list *info)
{
	double	num;
	int		unit_part;
	double	deci_part;

	num = va_arg(list, double);
	unit_part = num;
	deci_part = num - unit_part;
	print_decimal_part(unit_part, deci_part, info, "0123456789abcdef");
	return (1);
}

int	func_r(va_list list, t_list *info)
{
	(void)info;
	(void)list;
	return (1);
}

int	put_c_num(char c, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
	return (n);
}
