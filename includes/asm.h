/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 21:26:10 by hasni             #+#    #+#             */
/*   Updated: 2020/01/25 05:48:31 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/includes/libft.h"
# include <stdbool.h>
# include "op.h"

# define HAVE_NAME
# define HAVE_COMMENT

typedef struct	s_asm
{
    int			fd;
    char		*file_name;
	char		prog_name[PROG_NAME_LENGTH + 1];
	char		comment[COMMENT_LENGTH + 1];
}				t_asm;


int				ft_error(char *str, int ret);

void			init_asm(t_asm *asmb);

#endif