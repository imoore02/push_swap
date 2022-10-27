/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoore <imoore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:49:12 by isobelmoore       #+#    #+#             */
/*   Updated: 2022/10/21 14:34:53 by imoore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

int	err_chk(const char *str, int i, long long num)
{
	if (((!(str[i] >= '0' && str[i] <= '9')) && str[i] != '\0')
		|| num > 2147483647 || num < -2147483648)
		return (1);
	if (ft_strlen(str) == 1 && (str[0] == '-' || str[0] == '+'))
		return (1);
	return (0);
}

//-checks for duplicate integer values in a stack using a brute force method-//
void	check_dups(t_concept *info)
{
	t_stack	*end;
	t_stack	*other;

	end = info->a;
	while (1)
	{
		other = info->a->nxt;
		while (other != info->a)
		{
			if (info->a->num == other->num)
				fuck_error(info, ERROR_DUPLICATE);
			other = other->nxt;
		}
		info->a = info->a->nxt;
		if (info->a == end)
			break ;
	}
}

//--takes a char *string and turns it into an int *string--//
//notes: checks if the ints are valid;
int	*get_int_values(t_concept *info)
{
	int	*str;
	int	i;
	int	j;

	if (info->flag == 1)
		i = 0;
	else
		i = 1;
	j = 0;
	if (!info->argv[i])
		fuck_error(info, ERROR_ARGV);
	str = (int *)malloc(sizeof(int) * (info->stack_len + 1));
	if (!str)
		fuck_error(info, ERROR_MALLOC);
	while (info->argv[i])
	{
		str[j] = atoi_push_swap(info, info->argv[i]);
		i++;
		j++;
	}
	return (str);
}

//---altered ft_atoi does converts char *argv and turns in into an int---//
//notes: deals with (some of the) error checking; checks if only valid digit 
//       characters (including - or +(but only once right before the digit
//       & checks if it is an integer type
int	atoi_push_swap(t_concept *info, const char *str)
{
	int			i;
	int			neg;
	long long	res;
	long long	num;

	neg = 1;
	res = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	num = res * neg;
	if (err_chk(str, i, num) == 1)
		fuck_error(info, ERROR_INPUT_INVALID);
	return (num);
}

//--------taking the char*string arg and turning it into a DCLL--------//
//note: dcll = doubly circular linked list;
void	char_to_dcll(t_concept *info)
{
	int	*str;
	int	i;

	str = get_int_values(info);
	i = 0;
	while (i < info->stack_len)
	{
		add_node(info, &info->a, str[i], 0);
		i++;
	}
	if (!info->a)
		fuck_error(info, ERROR_STACK);
	check_dups(info);
	free(str);
	str = NULL;
}
