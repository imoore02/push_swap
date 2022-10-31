/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isobelmoore <isobelmoore@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:36:31 by imoore            #+#    #+#             */
/*   Updated: 2022/10/31 23:39:50 by isobelmoore      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

//_________SMALL SORT: SORTS STACKS WITH A LENGTH BETWEEN 2 AND 5___________//

/*/--stack compare function of 3 consecutive elements--/*/
//operation: each of the if statements represents a condition that a possible order of the stack of 3 (only 5 possible orders) will meet; each stack will meet 3 conditions; each condition has a value associated with it; 
//			 the value that a stack is assigned (the value that is retured) is the sum of the 3 values associated with the 3 conditions that the stack meets;
//           see here for an explanation: https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a
int	elem_compare_three(t_stack *current)
{
	t_stack	*i;
	t_stack	*j;
	int		result;

	result = 0;
	i = current->nxt;
	j = i->nxt;
	if (current->num > i->num)
		result += 1;
	if (current->num < i->num)
		result += 2;
	if (current->num > j->num)
		result += 7;
	if (current->num < j->num)
		result += 4;
	if (i->num > j-> num)
		result += 8;
	if (i->num < j->num)
		result += 13;
	return (result);
}
