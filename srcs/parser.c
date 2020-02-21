/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:40:50 by hasni             #+#    #+#             */
/*   Updated: 2020/02/21 05:20:14 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_bool	parse(t_asm *asmb)
{
	int ret;

	ret = 1;
	while (ret == 1)
	{
		// ft_strdel(&asmb->line);
		if ((ret = get_next_line(asmb->fd, &asmb->line)) == -1)
			return (1);
		// ft_printf("line : %s\n", asmb->line);
		if (asmb->line[0] == COMMENT_CHAR || asmb->line[0] == ';')
			;
		else if (ft_strnequ(asmb->line + ft_strspn(asmb->line, " \t"),
				NAME_CMD_STRING, 5))
		{
			if (parse_name(asmb))
				return (free_asm(asmb, 1));
		}
		else if (ft_strnequ(asmb->line + ft_strspn(asmb->line, " \t"),
				COMMENT_CMD_STRING, 7))
		{
			if (parse_comment(asmb))
				return (free_asm(asmb, 1));
		}
		else if (!parse_instruction(asmb))
			return (free_asm(asmb, 1));
		ft_strdel(&asmb->line);
	}
	// exit (1);
	if (check_parsing(asmb))
		return (free_asm(asmb, 1));
	return (0);
}
