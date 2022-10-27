/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_more.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoore <imoore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 20:44:43 by imoore            #+#    #+#             */
/*   Updated: 2022/10/21 12:56:33 by imoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	greatest_or_least(t_concept *info, int i)
{
	int	num;

	if (i == 1)
		num = info->least;
	else
		num = info->greatest;
	return (num);
}

//--finds whether the element that was pushed was the least or the greaest 
//and therefore whether it should go to the bottom or top of stack a--//
void	do_greatest_or_least(t_concept *info)
{
	if (info->do_least)
		rotate_a(info);
	if (info->do_greatest || !info->b)
		info->after_rotate++;
}

//--finds how many moves it will take a certain element in the stack (the chunk 
//pushed to stack b) to get to the top of the stack--//
void	find_moves_to_top(t_concept *info, t_stack *stack, int i)
{
	t_stack	*tmp;
	int		num;

	if (stack)
	{
		tmp = stack;
		num = greatest_or_least(info, i);
		while (tmp->num != num)
		{
			if (num == info->least)
				info->rotate_least++;
			else
				info->rotate_greatest++;
			tmp = tmp->nxt;
		}
	}
}

//--finds how many moves it will take a certain element in the stack (the 
//+chunk pushed to stack b) to get to the bottom of the stack--//

void	find_moves_to_bottom(t_concept *info, t_stack *stack, int i)
{
	t_stack	*tmp;
	int		num;

	if (stack)
	{
		tmp = stack;
		num = greatest_or_least(info, i);
		while (tmp->num != num)
		{
			if (num == info->least)
				info->rev_rotate_least++;
			else
				info->rev_rotate_greatest++;
			tmp = tmp->prev;
		}
	}
}
