/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 03:40:50 by hasni             #+#    #+#             */
/*   Updated: 2020/01/25 05:10:08 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// Change strncmp par strnqu
// Coder et comprendre strspn

t_bool  parse(t_asnm *asmb)
{
    char    *line;

    while (get_next_line(asmb->fd, &line))
    {
        if (line[0] == COMMENT_CHAR || line[0] == ';')
            ;
        else if (!ft_strncmp(line + ft_strspn(line, " \t"),
					NAME_CMD_STRING, 5) && parse_name(asmb, line))
			return (free_asm(asmb, 1));
        else if (!ft_strncmp(line + ft_strspn(line, " \t"),
					COMMENT_CMD_STRING, 7) && parse_comment(asmb, line))
			return (free_asm(asmb, 1));
        else if (!parse_instruction_line(asmb, line))
			return (free_asm(asmb, 1));
		ft_strdel(&line);
    }
    return (0);
}