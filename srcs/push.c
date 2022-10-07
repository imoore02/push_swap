/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isobelmoore <isobelmoore@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:20:46 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/09/20 10:40:38 by isobelmoore      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../libft/libft.h"

//--push a: pushes the first element at the top of stack b to the top of stack a--//
void	push_a(t_concept *info)
{
	int num;

	if(info->b)
	{
		num = info->b->num;
		del_node(info, &info->b);
		add_node(info, &info->a, num, 1);
	}
	write(1, "pa\n", 3);
}

//--push b: pushes the first element at the top of stack a to the top of stack b--//
void	push_b(t_concept *info)
{
	int num;

	if(info->a)
	{
		num = info->a->num;//takes the first value of the top of the b stack
		del_node(info, &info->a);
		add_node(info, &info->b, num, 1);
	}
	write(1, "pb\n", 3);
}