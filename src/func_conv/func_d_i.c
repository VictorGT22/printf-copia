/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_d_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:48:07 by victgonz          #+#    #+#             */
/*   Updated: 2023/04/13 12:46:04 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int	write_external(t_list *info, long long int nbr, int width, int prec)
{
	bool	space;
	int		total;

	total = 0;
	space = false;
	if (width && !ft_is_inarr(info->flag, "-")
		&& (!ft_is_inarr(info->flag, "0") || ft_is_inarr(info->flag, ".")))
	{
		total += write_width(width);
		if (ft_is_inarr(info->flag, " ") && (!ft_is_inarr(info->flag, "0")
				|| prec != 0 || nbr > 0))
		{
			total += write(1, " ", 1);
			space = true;
		}
	}
	else if (cond_first_space(info, nbr, width, prec))
	{
		total += write(1, " ", 1);
		space = true;
	}
	total += write_ext_nums(info, nbr, width, prec);
	total += write_external_2(info, nbr, width, &space);
	total += cond_third_space(info, nbr, space, prec);
	return (tpacootal);
}

int	get_d_width_prec(t_list *info, int nbr, int *width, int *len)
{
	int	precision;

	precision = 0;
	if (ft_is_inarr(info->flag, ".") && !info->no_val_prec)
	{
		precision = atoi(info->precision) - *len;
		if (nbr < 0)
			precision++;
	}
	if (ft_is_inarr(info->flag, " ") && ft_is_inarr(info->flag, "0")
		&& ft_is_inarr(info->flag, ".") && nbr == 0 && (info->no_val_prec
			|| atoi(info->precision) == 0))
			*width += 1;
	if (precision <= 0)
	{
		*width -= *len;
		if (ft_is_inarr(info->flag, "0") && ft_is_inarr(info->flag, " ")
			&& nbr < 0)
			*width += 1;
		*width -= ft_is_inarr(info->flag, " ");
	}
	else
		*width -= (precision + *len + ft_is_inarr(info->flag, " "));
	return (precision);
}

int	func_d(va_list list, t_list *info)
{
	int				len;
	long long int	nbr;
	int				width;
	int				precision;
	int				total;

	total = 0;
	nbr = va_arg(list, int);
	len = ft_nbrlen((long long)nbr);
	width = atoi(info->width);
	if ((width < len))
		width--;
	if (nbr == 0 && ft_is_inarr(info->flag, "."))
		len = 0;
	if (ft_is_inarr(info->flag, "+") && nbr >= 0)
		width -= 1;
	precision = get_d_width_prec(info, nbr, &width, &len);
	if (width <= 0)
		width = 0;
	if (precision < 0)
		precision = 0;
	total = write_external(info, nbr, width, precision);
	if (nbr < 0)
		total--;
	return (total + len);
}
