/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 02:32:56 by hasni             #+#    #+#             */
/*   Updated: 2020/01/31 01:10:21 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	check_param_num(char *str, char **arr, int param_num)
{
	int		i;
	int		sep_num;
	int		arr_num;

	i = 0;
	sep_num = 0;
	while (str[i])
		if (str[i++] == SEPARATOR_CHAR)
			sep_num++;
	arr_num = 0;
	while (arr[arr_num])
		arr_num++;
	if (arr_num != sep_num + 1)
		ft_error_line("too much separators");
	if (param_num != arr_num)
		ft_error_line("parameter number is wrong");
}

static void	get_inst_len(t_op *op, t_inst *inst, char type)
{
	if (type & T_REG)
		inst->len++;
	else if (type & T_DIR)
		inst->len += op->direct_len;
	else if (type & T_IND)
		inst->len += 2;
}

t_bool		check_param(char *str, t_op *op, t_inst *inst)
{
	char	**arr;
	char	*tmp;
	char	type;
	int		i;

	if (!(arr = ft_strsplit(str, SEPARATOR_CHAR)))
		ft_error_line("ft_strsplit failed in check_parameters");
	check_param_num(str, arr, op->param_num);
	i = -1;
	while (++i < op->param_num)
	{
		if (!(tmp = ft_strtrim(arr[i])))
			ft_error_line("ft_strtrim failed in check_parameters");
		ft_strdel(&arr[i]);
		arr[i] = tmp;
		if (!(type = get_param_type(arr[i], inst, i)))
			ft_error_line("ft_strtrim failed in check_parameters");
		if (!(type & op->param_type[i]))
			ft_error_line("input arguments have wrong type");
		check_type(arr[i], type);
		get_inst_len(op, inst, type);
		inst->param_num = op->param_num;
		inst->param_arr = arr;
	}
}
