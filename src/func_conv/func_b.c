/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:34:32 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/15 09:27:45 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/include/ft_printf.h"

int	func_b(va_list list, t_list *info)
{
	int					len;
	int					total;
	unsigned long int	nbr;
	int					width;

	total = 0;
	len = 0;
	nbr = va_arg(list, unsigned long int);
	ft_len_nbr_base(nbr, "01", &len);
	width = atoi(info->width) - len;
	if (width < 0)
		width = 0;
	if (width > 0 && !ft_is_inarr(info->flag, "-"))
		write_width(width);
	ft_putnbr_base(nbr, "01");
	if (width > 0 && ft_is_inarr(info->flag, "-"))
		write_width(width);
	return (width + len);
}
