/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isobelmoore <isobelmoore@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:14:59 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/10/31 16:16:21 by isobelmoore      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

//______________INITIALISES DATA AND MEMORY ALLOCATES_______________________//
//notes: initialises means to designate something w a value, this value is
//		 either a usefull value or just a place holder to later assign a 
//		 usefull value to (e.g. info->do_least = 0);

/*/-- initialises all of the required values/information necessary for 
completing the program --/*/
t_concept	*init_info(t_concept *info, char **argv, int argc)
{
	info = (t_concept *)malloc(sizeof(t_concept)); //(1) memory allocates for 1 't_concept struct';
	if (info == NULL) //(2) if the above memory allocation fails it will go into the error func;
		fuck_error(info, ERROR_MALLOC);
	info->a = NULL; //(2) initalises the first stack (type: struct t_stack *a) as NULL (nothing yet in it)
	info->b = NULL; //(3) as above;
	info->argv = argv; //(4) this assign the char **argv to the info->argv (which is also a char **string) -> this allows us to access it wherever the 't_concept *info' variable is passed as an argument;
	info->stack_len = argc - 1; //(5) reasoning as above; the int argc will be our stack length (unless the input was argc ==  2, with the second argument being a char *string e.g ./philo "5 9 3 1") -> in which case the argc will not be an accurate indicator of the size of the stack - and will instead find it using ft_countwords in 'push_swap()': pushswap.c, line 24;
	info->quarter = 0; //(6) initialised with a placeholder value; this value will represent the quarter value of our stack;
	info->median = 0; //(7) initialised with a placeholder value; this value will represent the median value of our stack;
	info->three_quar = 0;  //(8) initialised with a placeholder value; this value will represent the three_quar value of our stack;
	info->greatest = 0; //(9) initialised with a placeholder value; this value will represent the greatest value of our stack;
	info->rotate_greatest = 0; //(10) this represents a counter which will show how many moves it would take a the greatest value to get to the top of the chosen stack using 'rotate_a/b()': rotate.c, line 18/27;
	info->rev_rotate_greatest = 0; //(11) as above, but using 'rev_rotate_a/b()': reverse_rotate.c, line line 18/27;
	info->do_greatest = 0; //(12) this is a flag which will be used as an indicator as to whether the greatest or the least value should be moved (if it doesn't = 0 -> it means that the greatest value should be moved);
	info->least = 0; //(13) initialised with a placeholder value; this value will represent the least value of our stack;
	info->rotate_least = 0; //(14) this represents a counter which will show how many moves it would take a the least value to get to the top of the chosen stack using 'rotate_a/b()': rotate.c, line 18/27;
	info->rev_rotate_least = 0; //(15) as above, but using 'rev_rotate_a/b()': reverse_rotate.c, line line 18/27;
	info->do_least = 0; //(16) this is a flag which will be used as an indicator as to whether the greatest or the least value should be moved (if it doesn't = 0 -> it means that the least value should be moved);
	info->after_rotate = 0; //(17) see the guide, note 1; this represents the number of times stack a will need to be rotated at the end of a particular 
	info->flag = 0; //(18) a flag to represent whether the input was './push_swap 5 9 3 1' or './push_swap "5 9 3 1"';
	return (info);
}
