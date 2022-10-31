/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isobelmoore <isobelmoore@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:21:15 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/10/31 16:16:19 by isobelmoore      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

//START PROGRAM HERE:___________PUSH_SWAP MAIN SRC FILE______________________//

/*/-- fill stack a, if stack a is not sorted, it is put into a the solver 
function --/*/
void	push_swap(t_concept *info, int argc, char **argv)
{
	if (argc == 2) //(1) this case is used to check for if the input is './push_swap "5 9 3 1"'(only two arguments(int argc == 2), the second of which is a char string) instead of './push_swap 5 9 3 1' (this would have int argc == 5), where every argument is held in a char string double array;
	{
		info->stack_len = ft_countwords(argv[1], ' '); //(2) this finds out how many numbers are in the character string (e.g. in the example above (./philo "5 9 3 1") it would be 4) - so that we know how much memory to allocate for the stack -. it stores this value in info->stack_len (which will override whatever value is already there from the 'init_info()' function: init.c, line 30);
		if (info->stack_len > 1) //(3) if the char *string (e.g. ./push_swap "5 9 3 1") has more than one number (e.g. ./push_swap "5") then you need to split it into a char **string (e.g. which would create ./push_swap "5" "9" "3" "1" - which is the equivalent of ./push_swap 5 9 3 1)
		{
			info->argv = ft_split(argv[1], ' ');
			info->flag = 1; //(4) this flag relates to where you should start counting through the arguments from in the 'char_to_dcll()' function later -> this will need to be different depending on whether the input was ./push_swap 5 9 3 1 or ./push_swap "5 9 3 1";
		}
	}
	char_to_dcll(info); //(5) this function will put the char **string that we just created, into a doubly circular linked list (dcll);
	if (sorted(info) == 0) //(6) this will take the stack we just created as check if it is already sorted or not ->if its not it will put into 'sort_values()' to sort it;
	{
		sort_values(info); //(7) this will sort the stack;
	}
}

/*/-- creates a struct (t_concept *info) to conceptualise the project that holds
all info to complete the program (including stack a and b) --/*/
int	main(int argc, char **argv)
{
	t_concept	*info;

	info = NULL; //(1) must initialise info as NULL before it can be used as an argument;
	if (argc < 2) //(2) if user input is only ./push_swap then nothing will happen;
		return (1);
	info = init_info(info, argv, argc); //(3) preparation stage: initate all data strucutres and allocate the memory ready to begin the sorting;
	push_swap(info, argc, argv); //(4)do the sorting;
	clean_shit_up(info); //(5) once the sorting is done the memory will need to be freed;
	return (0);
}
