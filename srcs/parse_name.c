/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:02:52 by hasni             #+#    #+#             */
/*   Updated: 2020/01/25 04:13:57 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_bool	check_name(t_asm *asmb, char *str)
{
    int		n_start;
    int		n_len;
    char	*line;

	line = str + ft_strspn(str, " \t");
	n_len = ft_strcspn(line, " \t");
	n_start = n_len + ft_strspn(line + n_len, " \t");
	if (CHECK & HAVE_NAME)
		ft_error("Champion already has a name", 1);
	if (line[n_start] != '"')
		ft_error("could not find starting '\"' at the beginning of the name", 1);
	line += n_start + 1;
}
