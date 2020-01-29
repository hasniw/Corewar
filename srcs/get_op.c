/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:37:28 by hasni             #+#    #+#             */
/*   Updated: 2020/01/29 17:39:25 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_op	*get_op(char *instruction)
{
	int		i;

	i = 0;
	while (i < 16)
	{
		if (ft_strcmp(instruction, g_op_tab[i].instruction) == 0)
			return (&(g_op_tab[i]));
		i++;
	}
	return (NULL);
}
