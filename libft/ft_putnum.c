/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoore <imoore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 18:33:36 by imoore            #+#    #+#             */
/*   Updated: 2022/10/17 19:55:30 by imoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countstr(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i - 1);
}

int	ft_putnum(int str)
{
	int		i;
	char	*new;
	int		newleng;

	i = 0;
	new = ft_itoa(str);
	newleng = ft_countstr(new);
	i = ft_putstr(new);
	free(new);
	return (i);
}
