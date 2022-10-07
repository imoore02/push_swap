/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isobelmoore <isobelmoore@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:08:10 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/09/18 22:46:10 by isobelmoore      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"


//________CLEANS UP: PRINTS ERRORS(if any), FREES AND EXITS PROGRAM/EXECUTION_________//

//--

void	fuck_error(t_concept *info, char *errorcode)
{
	printf("%s", errorcode);
	clean_shit_up(info);
	exit(-1); //pls work out error codes lol;
}

void	free_stack(t_stack *stack)
{
	t_stack *current;
	t_stack *sacrifice;

	if(stack)
	{
		current = stack->nxt;
		while (current != stack)
		{
			sacrifice = current;
			current = current->nxt;
			free(sacrifice);
		}
		free(current);
	}
}

void	clean_shit_up(t_concept *info)
{
	if (info)
	{
		if (info->a)
			free_stack(info->a);
		if (info->b)
			free_stack(info->b);
		free(info);
	}
}