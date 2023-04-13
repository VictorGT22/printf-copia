/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:05:42 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/16 16:15:37 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include/ft_printf.h"

int	flag_sign(long long int *add_nbr, t_list *info)
{
	long long	nbr;

	nbr = *add_nbr;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
		*add_nbr = nbr;
		return (1);
	}
	if (ft_is_inarr(info->flag, "+") && nbr >= 0)
	{
		write (1, "+", 1);
		*add_nbr = nbr;
		return (1);
	}
	*add_nbr = nbr;
	return (0);
}

int	write_width(int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		write(1, " ", 1);
		i++;
	}
	return (width);
}

void	print_decimal_part(long num, double decimal, t_list *info, char *base)
{
	int	prec;
	int	i;
	int	len_base;

	i = 0;
	len_base = ft_strlen(base);
	ft_putnbr_base_l(num, base);
	if (strlen(info->precision) > 0)
		prec = atoi(info->precision);
	else
		prec = 6;
	if (prec > 0)
		write(1, ".", 1);
	while (0 < prec)
	{
		decimal *= 10;
		if (decimal < 0)
			decimal *= -1;
		ft_putnbr_base((int)decimal % len_base, base);
		prec--;
	}
}

int	func_module(va_list list, t_list *info)
{
	int	width;

	(void)list;
	width = atoi(info->width) - 1;
	if (width < 0)
		width = 0;
	if (width > 0 && !ft_is_inarr(info->flag, "-"))
		write_width(width);
	write(1, "%", 1);
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	return (1 + width);
}

int	get_exponent(double *num)
{
	int	count;

	count = 0;
	if (*num < 0)
	{
		*num *= -1;
		write(1, "-", 1);
	}
	while (*num / 10 >= 1.0)
	{
		count++;
		*num /= 10;
	}
	while (*num < 1.0)
	{
		count--;
		*num *= 10;
	}
	return (count);
}
