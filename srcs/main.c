/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 21:25:43 by hasni             #+#    #+#             */
/*   Updated: 2020/02/19 04:58:14 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <fcntl.h>

// void	printparser(t_asm *asmb)
// {
// 	t_inst *inst;
// 	t_label *labels;

// 	labels = asmb->labels;
// 	inst = asmb->inst;
// 	ft_printf("{yellow}<---LABELS--->{reset}\n");
// 	while (labels)
// 	{
// 		ft_printf("name : %s\n", labels->name);
// 		ft_printf("addr : %d\n", labels->addr);
// 		labels = labels->next;
// 	}
// 	ft_printf("{yellow}|------------|{reset}\n");
// 	ft_printf("{yellow}<---INST--->{reset}\n");
// 	int i;
// 	int j;
// 	while (inst)
// 	{
// 		i = 0;
// 		j = 0;
// 		ft_printf("inst->opcode : %c\n", inst->opcode);
// 		ft_printf("inst->ocp : %c\n", inst->ocp);
// 		ft_printf("inst->direct_len : %c\n", inst->direct_len);
// 		ft_printf("inst->param_byte : %d\n", inst->param_byte);
// 		ft_printf("inst->param_num : %c\n", inst->param_num);
// 		ft_printf("inst->addr : %d\n", inst->addr);
// 		ft_printf("inst->len : %d\n", inst->len);
// 		while (inst->param_arr[i])
// 		{
// 			j = 0;
// 			while (inst->param_arr[i][j])
// 			{
// 				ft_printf("inst->param_arr : %c\n", inst->param_arr[i][j]);
// 				j++;
// 			}
// 			i++;
// 		}
// 		inst = inst->next;
// 	}
// }

bool	handle_file(t_asm *file, int ac, char *av)
{
    int len;

    if (ac != 2)
        return (ft_error("format : ./asm champ.s", 1));
    len = ft_strlen(av);
    if (len <= 2 || av[len - 2] != '.' || av[len - 1] != 's' || av[len])
		return (ft_error("format : ./asm champ.s", 1));
    if ((file->fd = open(av, 0)) == -1)		
		return (ft_error("open file failed", 1));
    if (!(file->file_name = ft_strnew(len + 2)))
		return (ft_error("malloc failed", 1));
	ft_strncpy(file->file_name, av, len - 1);
	ft_strcat(file->file_name, "cor");
    return (0);
}

int     main(int ac, char **av)
{
	t_asm	asmb;

	init_asm(&asmb);
	// ft_printf("'%c'\n", 255);
	// ft_printf("'%c'\n", 0);
	// ft_printf("'%c'\n", 42);
	// exit (1);
	if (handle_file(&asmb, ac, av[1]))
		return (ft_error("Wrong input", -1));
	if (parse(&asmb))
		return (1);
	// ft_printf("PROG_NAME : %s | PROG_COMMENT : %s\n", asmb.prog_name, asmb.prog_comment);
	// ft_printf("{green}File to create : %s{reset}\n", asmb.file_name);
	if ((close(asmb.fd)) == -1)
		return (ft_error("close file failed", -1));
	ft_printf("{yellow}Just before output{reset}\n");
	// printparser(&asmb);
	if (output(&asmb))
		return (1);
	return (0);
}