/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isobelmoore <isobelmoore@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:21:01 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/09/20 10:43:10 by isobelmoore      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../libft/libft.h"

//--swap a: swaps the first 2 elements at the top of stack a--//

void	swap_a(t_concept *info)
{
	int tmp;
	
	if(info->a && (info->a->nxt != info->a))
	{
		tmp = info->a->num;
		info->a->num = info->a->nxt->num;
		info->a->nxt->num = tmp;
	}
	write(1, "sa\n", 3);
}
//notes:'top of stack a' = 1st element in the int array;


//--swap b: swaps the first 2 elements at the top of stack b--//
void	swap_b(t_concept *info)
{
	int tmp;

	if(info->b && (info->b->nxt != info->b))
	{
		tmp = info->b->num;
		info->b->num = info->b->nxt->num;
		info->b->nxt->num = tmp;
	}
	write(1, "sb\n", 3);
}

//--swap a and b: swaps both the first 2 elements at the top of stack a and stack b--//
void	ss(t_concept *info)
{
	int tmp;

	if(info->a && (info->a->nxt != info->a))
	{
		tmp = info->a->num;
		info->a->num = info->a->nxt->num;
		info->a->nxt->num = tmp;
	}
	if(info->b && (info->b->nxt != info->b))
	{
		tmp = info->b->num;
		info->b->num = info->b->nxt->num;
		info->b->nxt->num = tmp;
	}
	write(1, "ss\n", 3);
}