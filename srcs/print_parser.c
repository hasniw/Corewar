/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 03:40:59 by wahasni           #+#    #+#             */
/*   Updated: 2020/02/01 03:44:59 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	print_parser(t_asm *asmb)
{
	ft_printf("{red}FILE NAME IS : %s{reset}\n", asmb->file_name);
	ft_printf("{red}Name of the champ : %s\n{reset}\n", asmb->prog_name);
	ft_printf("{red}Comment of the champ : %s\n{reset}\n", asmb->prog_comment);
}
