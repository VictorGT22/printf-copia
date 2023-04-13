/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_s_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:57:19 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/22 14:12:28 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int	func_c(va_list list, t_list *info)
{
	char	c;
	int		total;
	int		width;

	total = 0;
	if (atoi(info->precision) > 0)
	{
		c = va_arg(list, int);
		width = atoi(info->width) - 1;
		if (width < 0)
			width = 0;
		if (width > 0 && !ft_is_inarr(info->flag, "-"))
			total += write_width(width);
		if (width > 0 && ft_is_inarr(info->flag, "-"))
			total += write_width(width);
		return (total);
	}
	return (total);
}

int	func_upper_c(va_list list, t_list *info)
{
	char	c;
	int		total;
	int		width;

	total = 0;
	if (atoi(info->precision) > 0)
	{
		c = va_arg(list, int);
		width = atoi(info->width) - 1;
		if (width < 0)
			width = 0;
		if (width > 0 && !ft_is_inarr(info->flag, "-"))
			total += write_width(width);
		total += write(1, &c, 1);
		if (width > 0 && ft_is_inarr(info->flag, "-"))
			total += write_width(width);
		return (total);
	}
	return (total);
}

int	get_len(t_list *info, char *s)
{
	int	len;

	if (ft_is_inarr(info->flag, ".") && !info->no_val_prec)
	{
		if (s && ft_strlen(s) < atoi(info->precision))
			len = ft_strlen(s);
		else if (!s && 6 <= atoi(info->precision))
			len = 6;
		else
			len = atoi(info->precision);
	}
	else if (ft_is_inarr(info->flag, ".") && info->no_val_prec)
		len = 0;
	else
	{
		if (s)
			len = ft_strlen(s);
		else
			len = 6;
	}
	return (len);
}

int	func_s(va_list list, t_list *info)
{
	char	*s;
	int		total;
	int		width;
	int		len;

	s = va_arg(list, char *);
	total = 0;
	len = get_len(info, s);
	width = atoi(info->width) - len;
	if (width < 0)
		width = 0;
	if (width > 0 && !ft_is_inarr(info->flag, "-"))
		total += write_width(width);
	if (s || !ft_is_inarr(info->flag, ".") || len != 0)
		total += ft_myputstr(s, info);
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		total += write_width(width);
	return (total);
}

int	func_upper_s(va_list list, t_list *info)
{
	char	*s;
	int		total;
	int		width;
	int		len;

	s = va_arg(list, char *);
	total = 0;
	len = get_len(info, s);
	width = atoi(info->width) - len;
	if (width < 0)
		width = 0;
	if (width > 0 && !ft_is_inarr(info->flag, "-"))
		total += write_width(width);
	if (s || !ft_is_inarr(info->flag, ".") || len != 0)
		total += ft_myputstr(s, info);
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		total += write_width(width);
	return (total);
}
