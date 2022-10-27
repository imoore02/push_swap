/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoore <imoore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:21:15 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/10/21 12:31:46 by imoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

//________PUSH_SWAP MAIN_________//

///--fill stack a, if stack a is not sorted, it is put into a the solver 
//function  --///
void	push_swap(t_concept *info, int argc, char **argv)
{
	if (argc == 2)
	{
		info->stack_len = ft_countwords(argv[1], ' ');
		if (info->stack_len > 1)
		{
			info->argv = ft_split(argv[1], ' ');
			info->flag = 1;
		}
	}
	char_to_dcll(info);
	if (sorted(info) == 0)
	{
		sort_values(info);
	}
}

//-- creates a concept struct (frame) that holds all info to complete program 
//(including stack a and b) --//
int	main(int argc, char **argv)
{
	t_concept	*info;

	info = NULL;
	if (argc < 2)
	{
		return (1);
	}
	info = init_info(info, argv, argc);
	push_swap(info, argc, argv);
	clean_shit_up(info);
	return (0);
}
