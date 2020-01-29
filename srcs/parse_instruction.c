/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:20:58 by hasni             #+#    #+#             */
/*   Updated: 2020/01/29 17:35:56 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void		remove_comment(char *str)
{
	int		i;

	i = ft_strchrindex(str, COMMENT_CHAR);
	if (i >= 0)
	{
		while (str[i])
			str[i++] = 0;
	}
}

static t_inst	*create_inst(t_asm *asmb, t_op *op)
{
	t_inst	*inst;

	if (!(inst = (t_inst *)malloc(sizeof(t_inst))))
		return (NULL);
	inst->opcode = op->opcode;
	inst->addr = asmb->accu_len;
	inst->len = 1 + op->ocp;
	inst->ocp = op->ocp;
	inst->direct_len = op->direct_len;
	return (inst);
}

static t_op		*check_inst(char *str)
{
	int		inst_len;
	char	*inst;
	t_op	*op;

	inst = NULL;
	inst_len = 0;
	while (str[inst_len] && !ft_isspace(str[inst_len]))
		inst_len++;
	if (!(inst = ft_strsub(str, 0, inst_len)))
		return (NULL);
	if (!(op = get_op(inst)))
		return (NULL);
	ft_strdel(&inst);
	return (op);
}

static t_bool	check_label_infront(t_asm *asmb, char *str)
{
	int		i;
	int		j;

	i = 0;
	while (str[i] && !ft_isspace(str[i]))
	{
		if (str[i] == LABEL_CHAR)
		{
			j = 0;
			while (j < i)
				if (!ft_strchr(LABEL_CHARS, str[j++]))
					return (ft_error("label contains non-LABEL_CHARS", 1));
			ft_list_push_back_label(&asmb->label, ft_strsub(str, 0, i), asmb->accu_len);
			return (i + 1);
		}
		i++;
	}
	return (0);
}

t_bool			parse_instruction(t_asm *asmb)
{
    char	*str;
	int		i;
	t_op	*op;
	t_inst	*inst;

	remove_comment(asmb->line);
	if (!(str = ft_strtrim(asmb->line)))
		return (1);
	i = check_label_infront(asmb, str);
	if (!str[i])
	    return (free_str_value(str, 1));
	i = skip_space(str, i);
	op = check_inst(str + i);
	inst = create_inst(asmb, op);
	i = skip_nonspace(str, i);
	i = skip_space(str, i);
	check_param(str + i, op, inst);
	asmb->accu_len += inst->len;
	ft_list_push_back_inst(&asmb->inst, inst);
	return (free_str_value(str, 1));
}
