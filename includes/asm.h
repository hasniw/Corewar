/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 21:26:10 by hasni             #+#    #+#             */
/*   Updated: 2020/01/31 20:01:16 by wahasni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/includes/libft.h"
# include "op.h"

# define HAVE_NAME 1
# define HAVE_COMMENT 2
# define t_bool int // => Voir comment opti 

typedef struct		s_op
{
	char			*instruction;
	char			param_num;
	char			param_type[3];
	char			opcode;
	int				cycle;
	char			*name;
	char			ocp;
	char			carry;
	char			direct_len;
}					t_op;

typedef struct		s_inst
{
	char			opcode;
	char			ocp;
	char			direct_len;
	int				param_byte;
	char			param_num;
	char			**param_arr;
	int				addr;
	int				len;
}					t_inst;

typedef struct		s_label
{
	char			*name;
	int				addr;
	struct s_label	*next;
}					t_label;

typedef struct		s_asm
{
    int				fd;
	char			*line;
    char			*file_name;
	char			prog_name[PROG_NAME_LENGTH + 1];
	char			prog_comment[COMMENT_LENGTH + 1];
	char			check;
	int				accu_len;
	t_inst			*inst;
	t_label			*labels;
}					t_asm;

/*
** ERROR
*/

int					ft_error(char *str, int ret);

/*
** INIT
*/

void				init_asm(t_asm *asmb);

/*
** PARSING
*/

t_bool				parse(t_asm *asmb);
t_bool				parse_name(t_asm *asmb);
t_bool				parse_comment(t_asm *asmb);
t_bool				parse_instruction(t_asm *asmb);
t_bool				check_parsing(t_asm *asmb);
t_bool				check_param(char *str, t_op *op, t_inst *inst);

/*
** UTILS
*/

int					skip_space(char *str, int i);
int					skip_nonspace(char *str, int i);

/*
** FREE
*/


#endif