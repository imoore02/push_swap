/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isobelmoore <isobelmoore@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:21:08 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/09/21 12:40:28 by isobelmoore      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
//# include <fnctl.h> //what does this one apply to?
# include "../libft/libft.h"

//--definitions of macros for variables in t_concept--//
//notes: so that its easier to write;
# define EIGHT info->eight
# define QUARTER info->quarter
# define EIGHT_THREE info->eight_three
# define MEDIAN info->median
# define EIGHT_FIVE info->eight_five
# define THREE_QUAR info->three_quar
# define EIGHT_SEVEN info->eight_seven
# define GREATEST info->greatest
# define LEAST info->least
# define ROTATE_LEAST info->rotate_least
# define REV_ROTATE_LEAST info->rev_rotate_least
# define ROTATE_GREATEST info->rotate_greatest
# define REV_ROTATE_GREATEST info->rev_rotate_greatest
# define DO_GREATEST info->do_greatest
# define DO_LEAST info->do_least

//--definitions of macros for error codes--//
# define ERROR_FREE "An error arose in whilst freeing :O\n"
# define ERROR_INPUT_INVALID "Invalid input (do it properly you shmuck): please enter valid integer(s). e.g. 420, 6969696969, +666, -8, 0\n"
# define ERROR_MALLOC "An error arose during memory allocation :O\n"
# define ERROR_INT_VALUES "An error arose in parsing values :O\n"
# define ERROR_SPLIT "An error arose in reading values :O\n"
# define ERROR_ARGV "An error arose it seems the argv was lost :O\n"
# define ERROR_STACK "An error arose in creating stack a :0\n"
# define ERROR_DUPLICATE "Invalid input: duplicate values detected :O\n"

//--structure to define the overall concept of the program: holds all necessary information to execute prog--//
typedef struct s_concept {

	//stacks
	struct s_stack	*a;
	struct s_stack	*b;

	char			**argv;

	int				stack_len;
	
	int				eight;
	int				quarter;
	int				eight_three;
	int				median;
	int				eight_five;
	int				three_quar;
	int				eight_seven;

	int				greatest;
	int				least;

	int				rotate_least;
	int				rev_rotate_least;
	int				rotate_greatest;
	int				rev_rotate_greatest;

	int				do_greatest;
	int				do_least;

	int				after_rotate;
} 					t_concept;

//--doubly circular linked list--//
typedef struct s_stack {
	int num; //4 bytes
	struct s_stack *prev; //4 bytes
	struct s_stack *nxt; //4 bytes (if 32 byte compiler)
} t_stack;

//--pushswap.c--//
void		push_swap(t_concept *info);

//--init.c--//
t_concept 	*init_info(t_concept *info, char **argv, int argc);

//--clean.c--//
void		fuck_error(t_concept *info, char *errorcode);
void		clean_shit_up(t_concept *info);
void		free_stack(t_stack *stack);

//--fill_stack.c--//
void 		char_to_dcll(t_concept *info);
int			*get_int_values(t_concept *info);
int			atoi_push_swap(t_concept *info, const char *str);

//--build_n_edit_stack.c--//
t_stack 	*init_stack(t_concept *info, int num);
void		add_node(t_concept *info, t_stack **first, int num, int true);
void		del_node(t_concept *info, t_stack **first);

//--master_sort.c--//
void		sort_values(t_concept *info);
int			sorted(t_concept *info);

//--small_sort.c--//
void		small_sort(t_concept *info);
void 		sort_five(t_concept *info);
void 		sort_two(t_concept *info);
void		sort_three(t_concept *info);
int			elem_compare_three(t_stack *current);

//--quarter_sort.c--//
void		push_quarters(t_concept *info, t_stack *stack, int i);
void 		quarter_sort(t_concept *info);
int			push_to_b(t_concept *info, int num, int lower_limit, int upper_limit, int middle);

//--actions.c--//
void		push_a(t_concept *info);
void		push_b(t_concept *info);
void		reverse_rotate_a(t_concept *info);
void		reverse_rotate_b(t_concept *info);
void		rrr(t_concept *info);
void		rotate_a(t_concept *info);
void		rotate_b(t_concept *info);
void		rr(t_concept *info);
void		swap_a(t_concept *info);
void		swap_b(t_concept *info);
void		ss(t_concept *info);

//--find_values.c--//
int			find_stack_len(t_concept *info, t_stack *stack);
void		sort_buff(int *buff, int len);
void		find_values(t_concept *info, t_stack *stack);
void		find_greatest_n_least(t_concept *info, t_stack *stack);
void		find_greatest(t_concept *info, t_stack *stack);
void		find_least(t_concept *info, t_stack *stack);

//--rotation.c--//
void		find_next_move(t_concept *info, t_stack *stack);
void 		moves_least(t_concept *info, t_stack *stack);
void		moves_greatest(t_concept *info, t_stack *stack);
void 		find_moves_to_top(t_concept *info, t_stack *stack, int i);
void 		find_moves_to_bottom(t_concept *info, t_stack *stack, int i);
int			greatest_or_least(t_concept *info, int i);
void		rotate_n_push_to_a(t_concept *info);
void		do_greatest_or_least(t_concept *info);
void		reset_moves(t_concept *info);

#endif