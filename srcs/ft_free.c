/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:26:03 by hasni             #+#    #+#             */
/*   Updated: 2020/02/21 04:14:41 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		free_just_inst(t_inst *inst, int ret)
{
	free(inst);
	return (ret);
}

int		free_tab(char **tab, int ret)
{
	int i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
	return (ret);
}

void	free_inst(t_inst *inst)
{
	t_inst	*tmp;

	while (inst)
	{
		free_tab(inst->param_arr, 0);
		tmp = inst->next;
		free(inst);
		inst = tmp;
	}
}

void	free_labels(t_label *labels)
{
	t_label	*tmp;

	while (labels)
	{
		ft_strdel(&labels->name);
		tmp = labels->next;
		free(labels);
		labels = tmp;
	}
}

int		free_asm(t_asm *asmb, int ret)
{
	ft_strdel(&asmb->file_name);
	if (asmb->labels)
		free_labels(asmb->labels);
	if (asmb->inst)
		free_inst(asmb->inst);
	return (ret);
}

int		free_str_value(char *str, int value)
{
	ft_strdel(&str);
	return (value);
}
