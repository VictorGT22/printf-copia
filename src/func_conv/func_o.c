/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:58:06 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/15 10:35:06 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int	func_o(va_list list, t_list *info)
{
	int				len;
	int				total;
	long long int	nbr;
	int				width;

	total = 0;
	len = 0;
	nbr = va_arg(list, int);
	ft_len_nbr_base(nbr, "01234567", &len);
	width = atoi(info->width) - len - ft_is_inarr(info->flag, "#");
	if (width < 0)
		width = 0;
	if (width > 0 && !ft_is_inarr(info->flag, "-"))
		write_width(width);
	if (ft_is_inarr(info->flag, "#"))
		total += write(1, "0", 1);
	ft_putnbr_base(nbr, "01234567");
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	return (width + len + ft_is_inarr(info->flag, "#"));
}

int	func_upper_o(va_list list, t_list *info)
{
	int				len;
	int				total;
	long long int	nbr;
	int				width;

	total = 0;
	len = 0;
	nbr = va_arg(list, int);
	ft_len_nbr_base(nbr, "01234567", &len);
	width = atoi(info->width) - len - ft_is_inarr(info->flag, "#");
	if (width < 0)
		width = 0;
	if (width > 0 && !ft_is_inarr(info->flag, "-"))
		write_width(width);
	if (ft_is_inarr(info->flag, "#"))
		total += write(1, "0", 1);
	ft_putnbr_base(nbr, "01234567");
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	return (width + len + ft_is_inarr(info->flag, "#"));
}
