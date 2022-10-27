/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoore <imoore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:14:59 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/10/21 12:47:51 by imoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

t_concept	*init_info(t_concept *info, char **argv, int argc)
{
	info = (t_concept *)malloc(sizeof(t_concept));
	if (info == NULL)
		exit(1);
	info->a = NULL;
	info->b = NULL;
	info->argv = argv;
	info->stack_len = argc - 1;
	info->quarter = 0;
	info->median = 0;
	info->three_quar = 0;
	info->greatest = 0;
	info->rotate_greatest = 0;
	info->rev_rotate_greatest = 0;
	info->do_greatest = 0;
	info->least = 0;
	info->rotate_least = 0;
	info->rev_rotate_least = 0;
	info->do_least = 0;
	info->after_rotate = 0;
	info->flag = 0;
	return (info);
}
