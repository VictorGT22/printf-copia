/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_func_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:19:54 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/22 08:50:48 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include/ft_printf.h"

int	ft_myputstr(char *str, t_list *info)
{
	int	i;
	int	len;

	i = 0;
	if (str == NULL)
		str = "(null)";
	if (ft_is_inarr(info->flag, "."))
		len = atoi(info->precision);
	else
		len = ft_strlen(str);
	if (info->no_val_prec)
		len = 0;
	while (str[i] != '\0' && i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void	ft_len_nbr_base(long long int nb, char *base, int *len)
{
	if (nb >= (long long)ft_strlen(base))
	{
		ft_len_nbr_base(nb / (long long)ft_strlen(base), base, len);
		ft_len_nbr_base(nb % (long long)ft_strlen(base), base, len);
	}
	if (nb < (long long)ft_strlen(base))
		*len += 1;
}

void	ft_len_nbr_base_u(unsigned long int nb, char *base, int *len)
{
	if (nb >= (unsigned long)ft_strlen(base))
	{
		ft_len_nbr_base_u(nb / (unsigned long)ft_strlen(base), base, len);
		ft_len_nbr_base_u(nb % (unsigned long)ft_strlen(base), base, len);
	}
	if (nb < (unsigned long)ft_strlen(base))
		*len += 1;
}
