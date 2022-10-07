/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quarter_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isobelmoore <isobelmoore@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:34:52 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/10/07 14:57:22 by isobelmoore      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	push(t_concept *info, t_stack *stack)
{
	t_stack *end;

	end = stack->prev;
	while (1)
	{
		while(stack->num != LEAST && stack->num != GREATEST)
			stack = stack->nxt;
		if (stack->num == LEAST || stack->num == GREATEST)
		{
			rotate_n_push_to_a(info);
			break;
		}
		else
			stack = stack->nxt;
		if (stack == end)
			break;
		stack = info->b;
	}
}

int	push_to_b(t_concept *info, int num, int lower_limit, int upper_limit, int middle)
{
	if(num > lower_limit && num <= upper_limit)
	{
		if(info->b && info->b->num > middle)
		{
			rotate_b(info);
		}
		push_b(info);
		return (0);
	}
	return (1);
}

void	push_quarters(t_concept *info, t_stack *stack, int i)
{
	t_stack *end;
	int ret;

	end = stack;
	int d = 0;
	while (d < info->stack_len)
	{
		if (i == 1)
			ret = push_to_b(info, stack->num, -2147483648, QUARTER, (QUARTER / 2));
		else if (i == 2)
			ret = push_to_b(info, stack->num, QUARTER, MEDIAN, (MEDIAN / 4) * 3);
		else if (i == 3)
			ret = push_to_b(info, stack->num, MEDIAN, THREE_QUAR, (MEDIAN / 4) * 5);
		else if (i == 4)
			ret = push_to_b(info, stack->num, THREE_QUAR, GREATEST, (MEDIAN / 4) * 7);
		else if (i == 4 && stack->num == LEAST)
				break ;
		if (ret == 1)
			rotate_a(info);
		stack = info->a;
		if(stack == end)
			break;
		d++;
	}
}

void 	quarter_sort(t_concept *info)
{
	int i;

	i = 1;
	find_values(info, info->a);
	while (info->a)
	{
		find_greatest_n_least(info, info->a);
		push_quarters(info, info->a, i);
		while (info->b)
		{	
			find_greatest_n_least(info, info->b);
			find_next_move(info, info->b);
			if (info->b && (ROTATE_LEAST >= 0 || REV_ROTATE_LEAST >= 0
				|| ROTATE_GREATEST >= 0 || REV_ROTATE_GREATEST >= 0))
			{
				rotate_n_push_to_a(info);
			}
		}
		while(info->after_rotate != 1)
		{
			--info->after_rotate;
			rotate_a(info);
		}
		info->after_rotate = 0;
		i++;
		if (i == 5)
			break;
	}
}