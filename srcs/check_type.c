/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 02:36:09 by hasni             #+#    #+#             */
/*   Updated: 2020/01/29 02:40:17 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	check_registry(char *str)
{
	int		num;

	str++;
	if (!ft_isdigit(*str) || *str == '0')
		return (ft_error("registry argument has wrong format", 1));
	num = ft_atoi(str);
	if (num < 1 || num > REG_NUMBER)
		return (ft_error("registry argument is out of the limit", 1));
	while (ft_isdigit(*str))
		str++;
	if (*str != '\0')
		return (ft_error("registry argument has wrong format", 1));
}

static void	check_number(char *str, char type)
{
	if (type & T_DIR)
		str++;
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (ft_error("number argument has wrong format", 1));
		str++;
	}
}

static void	check_label(char *str, char type)
{
	if (type & T_DIR)
		str++;
	str++;
	if (*str == 0)
		return (ft_error("no character after label char", 1));
	while (*str)
	{
		if (!ft_strchr(LABEL_CHARS, *str))
			return (ft_error("label argument has wrong format", 1));
		str++;
	}
}

void		check_type(char *str, int type)
{
	if (type & T_REG)
		check_registry(str);
	else if (type & T_LAB)
		check_label(str, type);
	else if (type & (T_DIR | T_IND))
		check_number(str, type);
}
