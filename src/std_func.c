/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victgonz <victgonz@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:19:54 by victgonz          #+#    #+#             */
/*   Updated: 2023/02/20 09:04:35 by victgonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include/ft_printf.h"

void	fill_operations3(t_fnc_ptr *operations)
{
	operations[20].op = 'G';
	operations[20].ptr = &func_upper_g;
	operations[21].op = 'a';
	operations[21].ptr = &func_a;
	operations[22].op = 'A';
	operations[22].ptr = &func_upper_a;
	operations[23].op = 'n';
	operations[23].ptr = &func_n;
	operations[24].op = 'b';
	operations[24].ptr = &func_b;
	operations[25].op = 'r';
	operations[25].ptr = &func_r;
	operations[26].op = 'p';
	operations[26].ptr = &func_p;
}

void	fill_operations2(t_fnc_ptr *operations)
{
	operations[10].op = 'x';
	operations[10].ptr = &func_x;
	operations[11].op = 'X';
	operations[11].ptr = &func_upper_x;
	operations[12].op = 'c';
	operations[12].ptr = &func_c;
	operations[13].op = 'C';
	operations[13].ptr = &func_upper_c;
	operations[14].op = '%';
	operations[14].ptr = &func_module;
	operations[15].op = 'e';
	operations[15].ptr = &func_e;
	operations[16].op = 'E';
	operations[16].ptr = &func_upper_e;
	operations[17].op = 'f';
	operations[17].ptr = &func_f;
	operations[18].op = 'F';
	operations[18].ptr = &func_upper_f;
	operations[19].op = 'g';
	operations[19].ptr = &func_g;
	fill_operations3(operations);
}

void	fill_operations(t_fnc_ptr *operations)
{
	operations[0].op = 's';
	operations[0].ptr = &func_s;
	operations[1].op = 'S';
	operations[1].ptr = &func_upper_s;
	operations[2].op = 'S';
	operations[2].ptr = &func_upper_s;
	operations[3].op = 'd';
	operations[3].ptr = &func_d;
	operations[4].op = 'D';
	operations[4].ptr = &func_d;
	operations[5].op = 'i';
	operations[5].ptr = &func_d;
	operations[6].op = 'o';
	operations[6].ptr = &func_o;
	operations[7].op = 'O';
	operations[7].ptr = &func_upper_o;
	operations[8].op = 'u';
	operations[8].ptr = &func_u;
	operations[9].op = 'U';
	operations[9].ptr = &func_upper_u;
	fill_operations2(operations);
}
