/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:27:41 by hasni             #+#    #+#             */
/*   Updated: 2020/01/30 22:53:16 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void    init_asm(t_asm *asmb)
{
    asmb->fd = 0;
    asmb->line = NULL;
    asmb->file_name = NULL;
    asmb->check = 0;
    ft_bzero(asmb->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(asmb->comment, COMMENT_LENGTH + 1);
    asmb->accu_len = 0;
	asmb->inst = NULL;
	asmb->labels = NULL;
}
