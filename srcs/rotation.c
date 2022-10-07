/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isobelmoore <isobelmoore@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 19:36:20 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/10/07 14:53:21 by isobelmoore      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

//________ROTATION FUNCTIONS________//

void	reset_moves(t_concept *info)
{
	GREATEST = 0;
	ROTATE_GREATEST = 0;
	REV_ROTATE_GREATEST = 0;
	DO_GREATEST = 0;
	LEAST = 0;
	ROTATE_LEAST = 0;
	REV_ROTATE_LEAST = 0;
	DO_LEAST = 0;
}

//--rotates through the chunk that was pushed to b, and pushes it back to a--//
void	rotate_n_push_to_a(t_concept *info)
{
	if (ROTATE_LEAST >= 0)
		while (ROTATE_LEAST--)
			rotate_b(info);
	else if (REV_ROTATE_LEAST >= 0)
		while (REV_ROTATE_LEAST--)
			reverse_rotate_b(info);
	else if (ROTATE_GREATEST >= 0)
		while (ROTATE_GREATEST--)
			rotate_b(info);
	else if (REV_ROTATE_GREATEST >= 0)
		while (REV_ROTATE_GREATEST--)
			reverse_rotate_b(info);
	push_a(info);
	do_greatest_or_least(info);
	reset_moves(info);
}

//--finds whether the element that was pushed was the least or the greaest and therefore whether it should go to the bottom or top of stack a--//
void	do_greatest_or_least(t_concept *info)
{
	if (DO_LEAST)
		rotate_a(info);
	if (DO_GREATEST || !info->b)
		info->after_rotate++;
}


//--finds which (the elemnet with the least or greatest) has the fewest moves to the top or the bottom of the stack--//
void	find_next_move(t_concept *info, t_stack *stack)
{
	moves_least(info, stack);
	moves_greatest(info, stack);
	//printf("RL%d, RG%d, RRL%d, RRG%d\n", ROTATE_LEAST, ROTATE_GREATEST, REV_ROTATE_LEAST, REV_ROTATE_GREATEST);
	if (ROTATE_GREATEST != -1 && (ROTATE_GREATEST >= ROTATE_LEAST &&
		ROTATE_GREATEST >= REV_ROTATE_LEAST))
		ROTATE_GREATEST = -1;
	else if (REV_ROTATE_GREATEST != -1 && (REV_ROTATE_GREATEST >= ROTATE_LEAST &&
		REV_ROTATE_GREATEST >= REV_ROTATE_LEAST))
		REV_ROTATE_GREATEST = -1;
	else if (ROTATE_LEAST != -1 && (ROTATE_LEAST >= ROTATE_GREATEST &&
		ROTATE_LEAST >= REV_ROTATE_GREATEST))
		ROTATE_LEAST = -1;
	else if (REV_ROTATE_LEAST != -1 && (REV_ROTATE_LEAST >= ROTATE_GREATEST &&
		REV_ROTATE_LEAST >= REV_ROTATE_GREATEST))
		REV_ROTATE_LEAST = -1;
	if (ROTATE_LEAST != -1 || REV_ROTATE_LEAST != -1)
		DO_LEAST = 1;
	else if (ROTATE_GREATEST != -1 || REV_ROTATE_GREATEST != -1)
		DO_GREATEST = 1;
}

//--finds whether it will take the element with the least value more moves to get to the top or the bottom of the stack (the chunk pushed to stack b)--//
void moves_least(t_concept *info, t_stack *stack)
{
	int i;

	i = 1;
	if (stack)
	{
		find_moves_to_top(info, stack, i);
		find_moves_to_bottom(info, stack, i);
		if (ROTATE_LEAST <= REV_ROTATE_LEAST)
			REV_ROTATE_LEAST = -1;
		else
			ROTATE_LEAST = -1;
	}
}

//--finds whether it will take the element with the greatest value more moves to get to the top or the bottom of the stack (the chunk pushed to stack b)--//
void moves_greatest(t_concept *info, t_stack *stack)
{
	int i;

	i = 0;
	if (stack)
	{
		find_moves_to_top(info, stack, i);
		find_moves_to_bottom(info, stack, i);
		if (ROTATE_GREATEST <= REV_ROTATE_GREATEST)
			REV_ROTATE_GREATEST = -1;
		else
			ROTATE_GREATEST = -1;
	}
}

//--finds how many moves it will take a certain element in the stack (the chunk pushed to stack b) to get to the top of the stack--//
void find_moves_to_top(t_concept *info, t_stack *stack, int i)
{
	t_stack *tmp;
	int num;

	if (stack)
	{
		tmp = stack;
		num = greatest_or_least(info, i);
		while (tmp->num != num)
		{
			if(num == LEAST)
				ROTATE_LEAST++;
			else
				ROTATE_GREATEST++;
			tmp = tmp->nxt; //can this be changed to tmp nxt?
		}
	}
}

//--finds how many moves it will take a certain element in the stack (the chunk pushed to stack b) to get to the bottom of the stack--//
void find_moves_to_bottom(t_concept *info, t_stack *stack, int i)
{
	t_stack *tmp;
	int num;

	if (stack)
	{
		tmp = stack;
		num = greatest_or_least(info, i);
		while (tmp->num != num)
		{
			if(num == LEAST)
				REV_ROTATE_LEAST++;
			else
				REV_ROTATE_GREATEST++;
			tmp = tmp->prev;
		}
	}
}

int	greatest_or_least(t_concept *info, int i)
{
	int num;
	if (i == 1)
		num = LEAST;
	else
		num = GREATEST;
	return (num);
}