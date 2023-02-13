/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:14:55 by adadoun           #+#    #+#             */
/*   Updated: 2023/02/10 16:14:58 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_tab(int *arr, int len)
{
	int	min;
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		min = arr[i];
		j = i + 1;
		while (j < len)
		{
			if (min > arr[j])
			{
				min = arr[j];
				arr[j] = arr[i];
				arr[i] = min;
			}
			j++;
		}
		i++;
	}
}

// int	ft_func(t_list **head, int *arr, int start, int end)
// {
// 	int	i;
// 	int	index;

// 	i = start;
// 	index = 1;
// 	while ((*head))
// 	{
// 		if (check_exist(arr, (*head)->i, start, end) == 1)
// 		{
// 			push_b(head, index);
// 		}
// 		index++;
// 		(*head) = (*head)->link;
// 	}
// }

void	push_b(t_list **head, t_list **head_b, int index) //gad liha head
{
	printf("index %i", index);
	if (index <= ft_lstsize((*head)) / 2)
	{
		while (index != 1)
		{
			ra(head, 1);
			index--;
		}
	}
	else if (index > ft_lstsize((*head)) / 2)
	{
		while (index == ft_lstsize((*head)) + 1)
		{
			rra(head, 1);
			index++;
		}
	}
	pb(head, head_b);
}

int	check_exist(int *arr, int nb, int start, int end)
{
	while (start <= end)
	{
		if (arr[start] == nb)
			return (1);
		start++;
	}
	return (0);
}
void	sort_100(t_list **head_a, t_list **head_b)
{
	int *arr;
	int offset;
	int middle;
	int start;
	int end;
	int index;
	int i;

	i = 0;
	index = 1;
	head_b = NULL;
	arr = tab((*head_a)); //free
	sort_tab(arr, ft_lstsize((*head_a)));
	while (i < ft_lstsize((*head_a)))
	{
		printf("arr %i\n", arr[i]);
		i++;
	}
	offset = ft_lstsize(*head_a) / 8;
	middle = ft_lstsize(*head_a) / 2 - 1;
	start = middle - offset;
	end = middle + offset;
	printf("start %i\n", start);
	printf("end %i\n", end);
	printf("middle %i\n", middle);
	printf("offset %i\n", offset);
	while (end >= 0 && start <= ft_lstsize(*head_a) - 1)
	{
		while ((*head_a))
		{
			if (check_exist(arr, (*head_a)->i, start, end) == 1)
			{
				push_b(head_a, head_b, index);
				// printf("yes %i exist\n", (*head_a)->i);
				// printf("index %i\n", index);
			}
			index++;
			(*head_a) = (*head_a)->link;
		}
		return ;
	}
}