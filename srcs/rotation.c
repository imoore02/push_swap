/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoore <imoore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 19:36:20 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/10/21 13:13:15 by imoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

//________ROTATION FUNCTIONS________//

void	reset_moves(t_concept *info)
{
	info->greatest = 0;
	info->rotate_greatest = 0;
	info->rev_rotate_greatest = 0;
	info->do_greatest = 0;
	info->least = 0;
	info->rotate_least = 0;
	info->rev_rotate_least = 0;
	info->do_least = 0;
}

//-rotates through the chunk that was pushed to b, and pushes it back to a-//
void	rotate_n_push_to_a(t_concept *info)
{
	if (info->rotate_least >= 0)
		while (info->rotate_least--)
			rotate_b(info);
	else if (info->rev_rotate_least >= 0)
		while (info->rev_rotate_least--)
			reverse_rotate_b(info);
	else if (info->rotate_greatest >= 0)
		while (info->rotate_greatest--)
			rotate_b(info);
	else if (info->rev_rotate_greatest >= 0)
		while (info->rev_rotate_greatest--)
			reverse_rotate_b(info);
	push_a(info);
	do_greatest_or_least(info);
	reset_moves(info);
}

//--finds which (the elemnet with the least or greatest) has the fewest
// moves to the top or the bottom of the stack--//
void	find_next_move(t_concept *info, t_stack *stack)
{
	moves_least(info, stack);
	moves_greatest(info, stack);
	if (info->rotate_greatest != -1
		&& (info->rotate_greatest >= info->rotate_least
			&& info->rotate_greatest >= info->rev_rotate_least))
		info->rotate_greatest = -1;
	else if (info->rev_rotate_greatest != -1
		&& (info->rev_rotate_greatest >= info->rotate_least
			&& info->rev_rotate_greatest >= info->rev_rotate_least))
		info->rev_rotate_greatest = -1;
	else if (info->rotate_least != -1
		&& (info->rotate_least >= info->rotate_greatest
			&& info->rotate_least >= info->rev_rotate_greatest))
		info->rotate_least = -1;
	else if (info->rev_rotate_least != -1
		&& (info->rev_rotate_least >= info->rotate_greatest
			&& info->rev_rotate_least >= info->rev_rotate_greatest))
		info->rev_rotate_least = -1;
	if (info->rotate_least != -1 || info->rev_rotate_least != -1)
		info->do_least = 1;
	else if (info->rotate_greatest != -1 || info->rev_rotate_greatest != -1)
		info->do_greatest = 1;
}

//--finds whether it will take the element with the least value more moves
//to get to the top or the bottom of the stack (the chunk pushed to stack b)//
void	moves_least(t_concept *info, t_stack *stack)
{
	int	i;

	i = 1;
	if (stack)
	{
		find_moves_to_top(info, stack, i);
		find_moves_to_bottom(info, stack, i);
		if (info->rotate_least <= info->rev_rotate_least)
			info->rev_rotate_least = -1;
		else
			info->rotate_least = -1;
	}
}

//--finds whether it will take the element with the greatest value more moves
//to get to the top or the bottom of the stack (the chunk pushed to stack b)//
void	moves_greatest(t_concept *info, t_stack *stack)
{
	int	i;

	i = 0;
	if (stack)
	{
		find_moves_to_top(info, stack, i);
		find_moves_to_bottom(info, stack, i);
		if (info->rotate_greatest <= info->rev_rotate_greatest)
			info->rev_rotate_greatest = -1;
		else
			info->rotate_greatest = -1;
	}
}
