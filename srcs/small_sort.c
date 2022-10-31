/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isobelmoore <isobelmoore@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:21:20 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/10/31 16:16:23 by isobelmoore      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include <stdio.h>

void	small_sort(t_concept *info)
{
	if (info->stack_len == 2)
		sort_two(info);
	if (info->stack_len == 3)
		sort_three(info);
	if (info->stack_len == 4)
		sort_four(info);
	if (info->stack_len == 5)
		sort_five(info);
}

//--sorts a stack with a length of 4 or 5--//
void	sort_five(t_concept *info)
{
	t_stack	*end;
	t_stack	*temp;
	int		len;

	end = info->a;
	find_values(info, info->a);
	len = 0;
	while (len < info->stack_len)
	{
		if (info->a->num < info->median)
			push_b(info);
		else
			rotate_a(info);
		len++;
	}
	sort_three(info);
	temp = info->b->nxt;
	if (info->b->num < temp->num)
		swap_b(info);
	push_a(info);
	push_a(info);
}

//--sorts a stack with a length of 2--//
void	sort_two(t_concept *info)
{
	if (info->a->num > info->a->nxt->num)
		swap_a(info);
}

//--sorts a stack with a length of 3--//
//notes: only 5 possible permeatations;
void	sort_three(t_concept *info)
{
	int	result;

	result = elem_compare_three(info->a);
	if (result == 21)
		rotate_a(info);
	if (result == 16)
	{
		swap_a(info);
		reverse_rotate_a(info);
	}
	if (result == 18)
		swap_a(info);
	if (result == 17)
		reverse_rotate_a(info);
	if (result == 14)
	{
		swap_a(info);
		rotate_a(info);
	}
}

void	sort_four(t_concept *info)
{
	t_stack	*temp;

	temp = info->a;
	find_greatest_n_least(info, info->a);
	while (temp->num != info->least)
	{
		rotate_a(info);
		temp = temp->nxt;
	}
	push_b(info);
	sort_three(info);
	push_a(info);
}
