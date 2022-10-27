/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoore <imoore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:36:31 by imoore            #+#    #+#             */
/*   Updated: 2022/10/21 17:45:54 by imoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

//--stack compush_are function of 3 consecutive elements--//
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
