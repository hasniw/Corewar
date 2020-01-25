/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hasni <hasni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 16:26:07 by hasni             #+#    #+#             */
/*   Updated: 2020/01/22 16:33:52 by hasni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int     ft_error(char *str, int ret)
{
    ft_printf("{red}%s{reset}\n", str);
    return (ret);
}