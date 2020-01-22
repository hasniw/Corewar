/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:27:41 by hasni             #+#    #+#             */
/*   Updated: 2020/01/22 19:10:51 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void    init_asm(t_asm *asmb)
{
    asmb->fd = 0;
    asmb->file_name = NULL;
    ft_bzero(asmb->prog_name, PROG_NAME_LENGTH + 1);
	ft_bzero(asmb->comment, COMMENT_LENGTH + 1);
}
