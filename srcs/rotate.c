/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isobelmoore <isobelmoore@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:20:57 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/09/18 22:46:04 by isobelmoore      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../libft/libft.h"

//--rotate a: shift up all elements of stack a by 1. the first element becomes the last one--//
void	rotate_a(t_concept *info)
{
	if(info->a)
		info->a = info->a->nxt;
	write(1, "ra\n", 3);
}

//--rotate b: shift up all elements of stack b by 1. the first element becomes the last one--//
void	rotate_b(t_concept *info)
{
	if(info->b)
		info->b = info->b->nxt;
	write(1, "rb\n", 3);
}

//--rotate a and b: shift up all elements of stack a and b by 1 both. the first element becomes the last one--//
void	rr(t_concept *info)
{
	if(info->a)
		info->a = info->a->nxt;
	if(info->b)
		info->b = info->b->nxt;
	write(1, "rr\n", 3);
}