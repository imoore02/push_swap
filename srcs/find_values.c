/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isobelmoore <isobelmoore@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:48:32 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/10/07 13:42:21 by isobelmoore      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

//--finds the length of a given stack--//
/*int	find_stack_len(t_concept *info, t_stack *stack)
{
	t_stack *end;

	info->stack_len = 0;
	if(stack)
		end = stack->prev;
	while(info->stack_len < 30)
	{
		info->stack_len++;
		if (stack == end)
			break;
		stack = stack->nxt;
	}
	printf("STACK :LEN %d\n\n\n\n", info->stack_len);
	return (info->stack_len);
	
}*/

//--bubble sorts through the buffer array and puts it in order--//
void	sort_buff(int *buff, int len) //why use long here
{
	long tmp;
	int i;

	tmp = 0;
	i = 0;
	while (i < (len - 1))
	{
		if (buff[i] < buff[i + 1])
			i++;
		else
		{
			tmp = buff[i];
			buff[i] = buff[i + 1];
			buff[i + 1] = tmp;
			i = 0;
		}
	}
}

//--finds the median value in an array--//
//operation: puts stack into an array (buff) and sorts through it;
void	find_values(t_concept *info, t_stack *stack)
{
	int *buff;
	int i;

	//info->stack_len = find_stack_len(info, stack);
	buff = (int*)malloc(sizeof(int) * (info->stack_len + 10));
	if (!buff)
		fuck_error(info, ERROR_MALLOC);
	i = 0;
	while (i < info->stack_len)
	{
		buff[i++] = stack->num;
		stack = stack->nxt;
	}
	//info->stack_len -= 1;
	sort_buff(buff, info->stack_len);
	i = 0;
	//while(i < info->stack_len)
	//{
	//	printf("element%d:  %d", i, buff[i]);
	//	i++;
	//}
	//printf("stack len %d", info->stack_len);
	QUARTER = buff[info->stack_len / 4];
	MEDIAN = buff[(info->stack_len / 4) * 2];
	THREE_QUAR = buff[(info->stack_len / 4) * 3];
	free(buff);
	buff = NULL;
	if (buff)
		fuck_error(info, ERROR_FREE);
}

void	find_greatest_n_least(t_concept *info, t_stack *stack)
{
	find_greatest(info, stack);;
	find_least(info, stack);
}

void	find_greatest(t_concept *info, t_stack *stack)
{
	t_stack *tmp;
	
	tmp = stack;
	GREATEST = tmp->num;
	while (1)
	{
		if(tmp->num > GREATEST)
			GREATEST = tmp->num;
		if(tmp == stack->prev)
			break;
		tmp = tmp->nxt;
	}
}

void	find_least(t_concept *info, t_stack *stack)
{
	t_stack *tmp;
	
	tmp = stack;
	LEAST = tmp->num;
	while (1)
	{
		if(tmp->num < LEAST)
			LEAST = tmp->num;
		if(tmp == stack->prev)
			break;
		tmp = tmp->nxt;
	}
}