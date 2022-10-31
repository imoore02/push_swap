/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_values.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isobelmoore <isobelmoore@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 12:48:32 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/10/31 23:40:40 by isobelmoore      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//_______________________FINDS VALUES WITHIN STACK__________________________//

#include "../includes/pushswap.h"

//--bubble sorts through the buffer array and puts it in order--//
void	sort_buff(int *buff, int len)
{
	long	tmp;
	int		i;

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
	int	*buff;
	int	i;

	buff = (int *)malloc(sizeof(int) * (info->stack_len + 10));
	if (!buff)
		fuck_error(info, ERROR_MALLOC);
	i = 0;
	while (i < info->stack_len)
	{
		buff[i++] = stack->num;
		stack = stack->nxt;
	}
	sort_buff(buff, info->stack_len);
	i = 0;
	info->quarter = buff[info->stack_len / 4];
	info->median = buff[(info->stack_len / 4) * 2];
	info->three_quar = buff[(info->stack_len / 4) * 3];
	free(buff);
	buff = NULL;
	if (buff)
		fuck_error(info, ERROR_FREE);
	find_greatest_n_least(info, stack);
}

void	find_greatest_n_least(t_concept *info, t_stack *stack)
{
	find_greatest(info, stack);
	find_least(info, stack);
}

void	find_greatest(t_concept *info, t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	info->greatest = tmp->num;
	while (1)
	{
		if (tmp->num > info->greatest)
			info->greatest = tmp->num;
		if (tmp == stack->prev)
			break ;
		tmp = tmp->nxt;
	}
}

void	find_least(t_concept *info, t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	info->least = tmp->num;
	while (1)
	{
		if (tmp->num < info->least)
			info->least = tmp->num;
		if (tmp == stack->prev)
			break ;
		tmp = tmp->nxt;
	}
}
