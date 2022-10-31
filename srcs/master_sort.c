/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isobelmoore <isobelmoore@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:17:10 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/10/31 22:55:31 by isobelmoore      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

//________________________SORTING FUNCTIONS_________________________________//

/*/-- checks the length of stack a and sorts it according to its size 
(whether its small or larger than 5) --/*/
void	sort_values(t_concept *info)
{
	if (info->stack_len <= 5) //(1) if the size of the stack (i.e. how many numbers are in the stack) is less than or equal to 5 then it will use the 'small_sort()' fucntion to sort it;
		small_sort(info); //(2) small_sort.c, line 16;
	if (info->stack_len > 5) //(3) if the size of the stack is larger than 5 -> it uses the 'quarter_sort()' function to sort it;
		quarter_sort(info); //(4) quarter_sort.c, line 90;
}


/*/-- checks whether the stack is already sorted (this is used in
'pushswap()'(pushswap.c, line 19)) --/*/
int	sorted(t_concept *info)
{
	t_stack	*end;
	t_stack	*current;

	current = info->a; //(1) puts the head pointer of stack a (t_stack *info->a) into 't_stack *current'; so that it can be used in the below comparisons without actually changing any of the values in the stack;
	end = info->a->prev; //(2) puts the pointer to the end of the stack (t_stack *info->a->prev (because its circular - see guide note 2)) into t_stack *end; so that it can be used in the below comparisons without actually changing any of the values in the stack;
	if (!info->a) //(3) if info->a doesn't exist return 0 (dont do anything); (which is what would happen if we didnt create our list properly (the code would ahve broken before this but its just a failsafe));
		return (0); //(4) it will return 0 to the function 'push_swap()' (pushswap.c, line 31);
	while (1) //(5) creation of an arbitrary loop - can only be broken with a 'break' call;
	{
		if (current == end) //(6) if the current pointer becomes the end pointer (i.e we have reached the end of the stack (aka the place we started from - because we only want to run through it once completely))
			break ;
		if (current->num > current->nxt->num) //(7) this checks if the 'int num' (number/value) stored in the current pointer is greater than the 'int num' in the next element in the stack (pointed to be t_stack *current->nxt); if it is greater this is UNSORTED and will return (0) to push_swap() (pushswap.c, line 19) to show that it needs to be sorted;
			return (0);
		current = current->nxt; //(8) this puts the pointer for 't_concept *current->nxt' into the pointer for 't_concept *current' -> therefore effectively moving to the next element in the stack;
	}
	return (1); //(9) if the stack is already in order it will return 1 to the function 'push_swap()' (pushswap.c, line 31);
}
