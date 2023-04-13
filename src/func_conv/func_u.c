/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:36:57 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/22 08:51:28 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int	get_u_width_prec(t_list *info, unsigned int nbr, int *width, int *len)
{
	int	precision;

	precision = 0;
	*width = atoi(info->width);
	if (nbr == 0 && ft_is_inarr(info->flag, "."))
		*len = 0;
	if (ft_is_inarr(info->flag, "+"))
		*width -= 1;
	if (ft_is_inarr(info->flag, "#") && nbr != 0)
		*width -= 2;
	if (ft_is_inarr(info->flag, ".") && !info->no_val_prec)
	{
		precision = atoi(info->precision) - *len;
		if (nbr < 0)
			precision++;
	}
	if (precision <= 0)
		*width -= *len;
	else
		*width -= (precision + *len);
	if (*width < 0)
		*width = 0;
	if (precision < 0)
		precision = 0;
	return (precision);
}

void	external_u_write(t_list *info, unsigned int nbr, int width, int prec)
{
	if (ft_is_inarr(info->flag, " ") && nbr >= 0 && (!width || !prec))
		write(1, " ", 1);
	if (ft_is_inarr(info->flag, "+"))
		write(1, "+", 1);
	if (prec > 0)
		put_c_num('0', prec);
	if (width > 0 && !ft_is_inarr(info->flag, ".")
		&& ft_is_inarr(info->flag, "0"))
		put_c_num('0', width + ft_is_inarr(info->flag, " "));
	if (nbr != 0 || !ft_is_inarr(info->flag, "."))
		ft_putnbr_base_l(nbr, "0123456789");
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
}

int	func_u(va_list list, t_list *info)
{
	int				len;
	unsigned int	nbr;
	int				width;
	int				precision;

	len = 0;
	nbr = va_arg(list, unsigned int);
	ft_len_nbr_base_u(nbr, "0123456789", &len);
	width = atoi(info->width);
	precision = get_u_width_prec(info, nbr, &width, &len);
	if (width > 0 && !ft_is_inarr(info->flag, "-")
		&& (!ft_is_inarr(info->flag, "0") || ft_is_inarr(info->flag, ".")))
		write_width(width);
	external_u_write(info, nbr, width, precision);
	if (ft_is_inarr(info->flag, " ") && nbr >= 0 && (!width || !precision))
	{
		width ++;
		if (ft_is_inarr(info->flag, "+"))
			width ++;
	}
	return (width + len + precision);
}

int	func_upper_u(va_list list, t_list *info)
{
	int				len;
	unsigned int	nbr;
	int				width;
	int				precision;

	len = 0;
	nbr = va_arg(list, unsigned int);
	ft_len_nbr_base_u(nbr, "0123456789", &len);
	width = atoi(info->width);
	precision = get_u_width_prec(info, nbr, &width, &len);
	if (width > 0 && !ft_is_inarr(info->flag, "-")
		&& (!ft_is_inarr(info->flag, "0") || ft_is_inarr(info->flag, ".")))
		write_width(width);
	external_u_write(info, nbr, width, precision);
	if (ft_is_inarr(info->flag, " ") && nbr >= 0 && (!width || !precision))
	{
		width ++;
		if (ft_is_inarr(info->flag, "+"))
			width ++;
	}
	return (width + len + precision);
}
