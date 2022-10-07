/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isobelmoore <isobelmoore@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:21:15 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/10/07 14:56:59 by isobelmoore      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

//________PUSH_SWAP MAIN_________//

///--fill stack a, if stack a is not sorted, it is put into a the solver function  --///
void	push_swap(t_concept *info) //you could put static but its not really necessary for these projects (because your not making any function that is going to try and call this outside of your compilable unit)
{
	char_to_dcll(info);
	if (sorted(info) == 0)
	{
		sort_values(info);
	}
}

//-- creates a concept struct (frame) that holds all info to complete program (including stack a and b) --//
int	main(int argc, char **argv)
{
	t_concept *info;

	info = NULL; //should i set up a function to init this instead??
	if (argc < 2)
	{
		return (1);
	}
	info = init_info(info, argv, argc);
	push_swap(info);
	clean_shit_up(info);
	return (0);
}