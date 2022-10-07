/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isobelmoore <isobelmoore@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:21:20 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/09/21 15:04:29 by isobelmoore      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

void	small_sort(t_concept *info)
{
	if (info->stack_len == 2)
		sort_two(info);
	if (info->stack_len == 3)
		sort_three(info);
	//if(info->stack_len == 4)
	//	sort_four(info);
	if (info->stack_len == 5)
		sort_five(info);
}

//--sorts a stack with a length of 4 or 5--//
void sort_five(t_concept *info)
{
	push_b(info);
	push_b(info);
	sort_three(info);
	if (info->b->num < info->b->nxt->num)
	{
		rotate_b(info);
	}
	push_a(info);
	rotate_a(info);
	push_a(info);
}

//--sorts a stack with a length of 2--//
void sort_two(t_concept *info)
{
	if(info->a->num > info->a->nxt->num)
		swap_a(info);
}

//--sorts a stack with a length of 3--//
//notes: only 5 possible permeatations;
void	sort_three(t_concept *info)
{
	int result;
	
	result = elem_compare_three(info->a);
	if (result == 10)
		rotate_a(info);
	if (result == 12)
	{
		swap_a(info);
		reverse_rotate_a(info);
	}
	if (result == 11)
		swap_a(info);
	if (result == 13)
		reverse_rotate_a(info);
	if (result == 14)
	{
		swap_a(info);
		rotate_a(info);
	}
}

//--stack compush_are function of 3 consecutive elements--//
int	elem_compare_three(t_stack *current) //this way you dont need to use an areverse_rotate_ay to compush_are the elements and the lines dotn get too funcking long
{
	t_stack *i;
	t_stack *j;
	int result;

	result = 0;
	i = current->nxt;
	j = i->nxt;
	if (current->num > i->num)
		result += 1;
	if (current->num < i->num)
		result += 2;
	if (current->num > j->num)
		result += 3;
	if (current->num < j->num)
		result += 4;
	if (i->num > j-> num)
		result += 8;
	if (i->num < j->num)
		result += 6;
	return (result);
}