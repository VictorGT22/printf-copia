/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 18:04:21 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/15 17:47:05 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include/ft_printf.h"

int	func_ptr(t_Main *var, va_list list)
{
	int	i;

	i = 0;
	while (i < var->num_conv)
	{
		if (var->current_ptr->conv == var->arr_func[i].op)
			return ((*(var->arr_func[i].ptr))(list, var->current_ptr));
		i++;
	}
	return (0);
}
