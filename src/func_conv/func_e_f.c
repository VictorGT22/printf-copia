/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_e_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 10:51:48 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/15 10:30:37 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int	get_e_width(t_list *info, long unit_part, int *width, int *exp)
{
	int	num;

	num = 0;
	*width = atoi(info->width) - (ft_nbrlen(unit_part) + 2
			+ atoi(info->precision) + ft_nbrlen((long long) exp));
	if (*exp > 0)
		*width -= 1;
	if (*exp > -10 && *exp < 10)
	{
		*width -= 1;
		if (*exp > 0)
			num++;
		num++;
	}
	if (*width < 0)
		*width = 0;
	return (num);
}

int	func_e(va_list list, t_list *info)
{
	int		exp;
	int		width;
	double	num;
	long	unit_part;
	double	deci_part;

	num = va_arg(list, double);
	exp = get_exponent(&num);
	unit_part = num;
	deci_part = num - unit_part;
	num = get_e_width(info, unit_part, &width, &exp);
	if (width > 0 && !ft_is_inarr(info->flag, "-"))
		write_width(width);
	print_decimal_part(unit_part, deci_part, info, "0123456789");
	write(1, "e", 1);
	write_exp(exp);
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	num += width + ft_nbrlen(unit_part) + 2
		+ ft_nbrlen((long long)exp) + atoi(info->precision);
	return (num);
}

int	func_upper_e(va_list list, t_list *info)
{
	int		exp;
	int		width;
	double	num;
	long	unit_part;
	double	deci_part;

	num = va_arg(list, double);
	exp = get_exponent(&num);
	unit_part = num;
	deci_part = num - unit_part;
	num = get_e_width(info, unit_part, &width, &exp);
	if (width > 0 && !ft_is_inarr(info->flag, "-"))
		write_width(width);
	print_decimal_part(unit_part, deci_part, info, "0123456789");
	write(1, "E", 1);
	write_exp(exp);
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	num += width + ft_nbrlen(unit_part) + 2
		+ ft_nbrlen((long long)exp) + atoi(info->precision);
	return (num);
}

int	func_f(va_list list, t_list *info)
{
	int		width;
	double	num;
	int		unit_part;
	double	deci_part;

	num = va_arg(list, double);
	unit_part = num;
	deci_part = num - unit_part;
	width = atoi(info->width) - (ft_nbrlen(unit_part) + 1
			+ atoi(info->precision));
	if (width < 0)
		width = 0;
	if (width > 0 && !ft_is_inarr(info->flag, "-"))
		write_width(width);
	print_decimal_part(unit_part, deci_part, info, "0123456789");
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	return (width + ft_nbrlen(unit_part) + 1
		+ atoi(info->precision));
}

int	func_upper_f(va_list list, t_list *info)
{
	int		width;
	double	num;
	int		unit_part;
	double	deci_part;

	num = va_arg(list, double);
	unit_part = num;
	deci_part = num - unit_part;
	width = atoi(info->width) - (ft_nbrlen(unit_part) + 1
			+ atoi(info->precision));
	if (width < 0)
		width = 0;
	if (width > 0 && !ft_is_inarr(info->flag, "-"))
		write_width(width);
	print_decimal_part(unit_part, deci_part, info, "0123456789");
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	return (width + ft_nbrlen(unit_part) + 1
		+ atoi(info->precision));
}
