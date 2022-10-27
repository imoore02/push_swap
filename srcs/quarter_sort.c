/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quarter_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoore <imoore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:34:52 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/10/21 13:12:49 by imoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	push(t_concept *info, t_stack *stack)
{
	t_stack	*end;

	end = stack->prev;
	while (1)
	{
		while (stack->num != info->least && stack->num != info->greatest)
			stack = stack->nxt;
		if (stack->num == info->least || stack->num == info->greatest)
		{
			rotate_n_push_to_a(info);
			break ;
		}
		else
			stack = stack->nxt;
		if (stack == end)
			break ;
		stack = info->b;
	}
}

int	push_to_b(t_concept *info, int num, int lower_limit, int upper_limit)
{
	int	middle;

	if (upper_limit == info->quarter)
		middle = info->quarter * 2;
	else if (upper_limit == info->median)
		middle = (info->median / 4) * 3;
	else if (upper_limit == info->three_quar)
		middle = (info->median / 4) * 5;
	else if (upper_limit == info->greatest)
		middle = (info->median / 4) * 7;
	if (num > lower_limit && num <= upper_limit)
	{
		if (info->b && info->b->num > middle)
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
	t_stack	*end;
	int		ret;
	int		d;

	end = stack;
	d = 0;
	while (d < info->stack_len)
	{
		if (i == 1)
			ret = push_to_b(info, stack->num, -2147483648, info->quarter);
		else if (i == 2)
			ret = push_to_b(info, stack->num, info->quarter, info->median);
		else if (i == 3)
			ret = push_to_b(info, stack->num, info->median, info->three_quar);
		else if (i == 4)
			ret = push_to_b(info, stack->num, info->three_quar, info->greatest);
		else if (i == 4 && stack->num == info->least)
			break ;
		if (ret == 1)
			rotate_a(info);
		stack = info->a;
		if (stack == end)
			break ;
		d++;
	}
}

void	quarter_sort(t_concept *info)
{
	int	i;

	i = 1;
	while (info->a)
	{
		find_values(info, info->a);
		push_quarters(info, info->a, i);
		while (info->b)
		{	
			find_greatest_n_least(info, info->b);
			find_next_move(info, info->b);
			if (info->b)
			{
				if (info->rotate_least >= 0 || info->rev_rotate_least >= 0
					|| info->rotate_greatest >= 0
					|| info->rev_rotate_greatest >= 0)
					rotate_n_push_to_a(info);
			}
		}
		do_after_rotate(info);
		i++;
		if (i == 5)
			break ;
	}
}

void	do_after_rotate(t_concept *info)
{
	while (info->after_rotate != 1)
	{
		--info->after_rotate;
		rotate_a(info);
	}
		info->after_rotate = 0;
}
