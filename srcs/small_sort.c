/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isobelmoore <isobelmoore@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:21:20 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/10/31 23:35:19 by isobelmoore      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include <stdio.h>

//_________SMALL SORT: SORTS STACKS WITH A LENGTH BETWEEN 2 AND 5___________//


/*/-- main small sort function - contains an opertation route for all possible lengths --/*/
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

/*/-- sorts a stack with a length of 5 --/*/
void	sort_five(t_concept *info)
{
	t_stack	*end;
	t_stack	*temp;
	int		len;

	end = info->a; //(1) assigns the value of 't_stack *info->a' to 't_stack *end'; such that we can use this value without changing it at the source;
	find_values(info, info->a); //(2) find_values -> finds all the values e.g. median, least, three_quarters and assigns them inside the 't_concept *info' structure so that they can be accessible wherever it is passed;
	len = 0;
	while (len < info->stack_len) //(3) this will allow us to move through the entire length of the stack once;
	{
		if (info->a->num < info->median) //(4) if we access a value that is below the median value then we will push it to stack b; seperating the bottom half (in value) of the stack from the top half of the stack; this will only push 2 elements;
			push_b(info);
		else
			rotate_a(info); 
		len++;
	}
	sort_three(info); //(5) it will then use the sort_three() fucntion to sort the remaining three values in the stack;
	temp = info->b->nxt; //(6) assigns the value of 't_stack *info->b->nxt' to 't_stack *temp'; such that we can use this value without changing it at the source;
	if (info->b->num < temp->num) //(7) checks whether the value in the head element of stack b is lesser than the value in the next element in b; if it is we swap them so that when they are pushed to a they will land in ascending order;
		swap_b(info);
	push_a(info); //(8) push the two elements that were in stack b;
	push_a(info);
}

/*/-- sorts a stack with a length of 2 --/*/
void	sort_two(t_concept *info)
{
	if (info->a->num > info->a->nxt->num) //(1) if the first number in the  stack is greater than the second then swap them;
		swap_a(info);
}

/*/-- sorts a stack with a length of 3 --/*/
//notes: only 5 possible permeatations; see guide, note 3;
void	sort_three(t_concept *info)
{
	int	result;

	result = elem_compare_three(info->a); //(1) instead of writing out the conditions for each possible circumstance (of which there would be a combination of 3 conditions); i made a function (elem_compare_three() (small_sort_more.c, line 16)) that would assign a value to each condition sigularly - as each circumstance has a different combination of these conditions they will all have a different cumulative value/result;
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

/*/-- sorts a stack with a length of 4 --/*/
void	sort_four(t_concept *info)
{
	t_stack	*temp;

	temp = info->a;
	find_greatest_n_least(info, info->a); //(1) finds the greatest value and the least value in stack a;
	while (temp->num != info->least) //(2) while the stack doesnt reach the element containing the least value it will rotate;
	{
		rotate_a(info);
		temp = temp->nxt;
	}
	push_b(info); //(3) when temp num does equal the least (i.e least is at the top of the stack) -> it will push it to stack b;
	sort_three(info); //(4) it will then use the sort_three() fucntion to sort the remainign three values in the stack;
	push_a(info); //(5) once the three elements in stack a are sorted into the correct ascending order -> the least value (which is still sitting in stack b) will be push back to the top of stack a;
}
