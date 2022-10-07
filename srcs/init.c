/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isobelmoore <isobelmoore@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:14:59 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/10/07 13:41:28 by isobelmoore      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

t_concept *init_info(t_concept *info, char **argv, int argc)
{
	info = (t_concept *)malloc(sizeof(t_concept));
	if (info == NULL)
		exit(1); //figure out wtf exit codes mean + print an error here?
	info->a = NULL;
	info->b = NULL;
	info->argv = argv;
	info->stack_len = argc - 1;
	QUARTER = 0;
	MEDIAN = 0;
	THREE_QUAR = 0;
	GREATEST = 0;
	ROTATE_GREATEST = 0;
	REV_ROTATE_GREATEST = 0;
	DO_GREATEST = 0;
	LEAST = 0;
	ROTATE_LEAST = 0;
	REV_ROTATE_LEAST = 0;
	DO_LEAST = 0;
	info->after_rotate = 0;
	return(info);
}