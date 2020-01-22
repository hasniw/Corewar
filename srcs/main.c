/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 21:25:43 by hasni             #+#    #+#             */
/*   Updated: 2020/01/22 19:19:12 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include <fcntl.h>

bool  handle_file(t_asm *file, int ac, char *av)
{
    int len;

    if (ac != 2)
        return (1);
    len = ft_strlen(av);
    if (len <= 2 || av[len - 2] != '.' || av[len - 1] != 's' || av[len])
		return (1);
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
    t_asm   asmb;
    
    init_asm(&asmb);
    if (handle_file(&asmb, ac, av[1]))
        return (ft_error("Wrong input", -1));
    ft_printf("{green}File to create : %s{reset}\n", asmb.file_name);
    // if (parse_champ(asmb))
    //     return (ft_error("Wrong champ", -1));
    return (0);
}