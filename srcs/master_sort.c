/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isobelmoore <isobelmoore@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:17:10 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/10/07 14:51:57 by isobelmoore      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

//_________SORTING FUNCTIONS__________//

//--master sort function--//
//operation: checks the length of stack a and sorts it accordingly--//
void	sort_values(t_concept *info)
{
	if (info->stack_len <= 5)
		small_sort(info);
	if (info->stack_len > 5)
		quarter_sort(info);
}

int	sorted(t_concept *info)
{
	t_stack *end;
	t_stack *current;

	current = info->a;
	end = info->a->prev;
	if (!info->a)
		return (0);
	while(1)
	{
		if(current == end)
			break;
		if(current->num > current->nxt->num)
			return (0);
		current = current->nxt;
	}
	return (1);
}