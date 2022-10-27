/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoore <imoore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:20:54 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/10/21 12:35:01 by imoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../libft/libft.h"

//--reverse rotate a: shift down all elements of stack a by 1. the last
// element becomes the first one--//
void	reverse_rotate_a(t_concept *info)
{
	if (info->a)
		info->a = info->a->prev;
	write(1, "rra\n", 4);
}

//--reverse rotate b: shift down all elements of stack b by 1. the last element
//becomes the first one--//
void	reverse_rotate_b(t_concept *info)
{
	if (info->b)
		info->b = info->b->prev;
	write(1, "rrb\n", 4);
}

//--rev rotate a and b: shift down all elements of stack a and b by 1 both.
// the last element becomes the first one--//
void	rrr(t_concept *info)
{
	if (info->a)
		info->a = info->a->prev;
	if (info->b)
		info->b = info->b->prev;
	write(1, "rrr\n", 4);
}
