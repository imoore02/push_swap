/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_n_edit_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isobelmoore <isobelmoore@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:41:06 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/09/20 12:25:31 by isobelmoore      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

//--------creating (initiating and mallocing) doubly circular linked list--------//

//--adding the new node to the sacrifice(if int true == 1 - the head pointer) or bottom of the list--//
//notes: something will need to be freed but ideally when the list is cleared (end of program) or when a node is deleted
void	add_node(t_concept *info, t_stack **first, int num, int true)
{
	t_stack *new;
	t_stack *end;
	
	if (*first)
	{
		new = (t_stack *)malloc(sizeof(t_stack));
		if(new == NULL)
			fuck_error(info, ERROR_MALLOC);
		end = (*first)->prev;
		new->nxt = (*first);
		new->prev = end;
		(*first)->prev = new;
		end->nxt = new;
		new->num = num;
		if(true == 1)
			(*first) = (*first)->prev;
	}
	else
		(*first) = init_stack(info, num);
}

//--initiating the head pointer of a stack--//
t_stack *init_stack(t_concept *info, int num)
{
	t_stack *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if(new == NULL)
		fuck_error(info, ERROR_MALLOC);
	new->nxt = new;
	new->prev = new;
	new->num = num;
	return (new);
}

//--deletes a node from the top of the list (and sets the nxtnode to be head pointer)--//
void	del_node(t_concept *info, t_stack **sacrifice)
{
	t_stack		*tmp;

	if (*sacrifice)
	{
		if ((*sacrifice)->nxt == (*sacrifice))
		{
			free(*sacrifice);
			(*sacrifice) = NULL;
			if (*sacrifice)
				fuck_error(info, ERROR_FREE);
		}
		else
		{
			tmp = (*sacrifice);
			(*sacrifice) = (*sacrifice)->nxt;
			tmp->prev->nxt = (*sacrifice);
			(*sacrifice)->prev = tmp->prev;
			free(tmp);
			tmp = NULL;
			if (tmp)
				fuck_error(info, ERROR_FREE);
		}
	}
}