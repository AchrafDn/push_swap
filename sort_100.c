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

int	check_exist(int *arr, int nb, t_struct *ptr)
{
	int	i;

	i = ptr->start;
	while (i <= ptr->end)
	{
		if (arr[i] == nb)
			return (1);
		i++;
	}
	return (0);
}

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

void	initialize_struct(t_list **head_a, t_struct *ptr)
{
	int	i;

	if (ft_lstsize((*head_a)) <= 10)
		i = 5;
	if (ft_lstsize((*head_a)) <= 150)
		i = 8;
	if (ft_lstsize((*head_a)) > 150)
		i = 18;
	ptr->index = 1;
	ptr->arr = tab((*head_a)); //free
	sort_tab(ptr->arr, ft_lstsize((*head_a)));
	ptr->offset = ft_lstsize(*head_a) / i;
	ptr->middle = ft_lstsize(*head_a) / 2 - 1;
	ptr->start = ptr->middle - ptr->offset;
	ptr->end = ptr->middle + ptr->offset;
	ptr->len_array = ft_lstsize((*head_a));
}

void	push_b(t_list **head, t_list **head_b, int index, t_struct *ptr)
{
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
		while (index <= ft_lstsize((*head)))
		{
			rra(head, 1);
			index++;
		}
	}
	pb(head, head_b);
	if ((*head_b)->i <= ptr->arr[ptr->middle])
		rb(head_b, 1);
}

void	push_stack_b(t_list **head_a, t_list **head_b, t_struct *ptr)
{
	t_list	*temp;

	while ((*head_a))
	{
		temp = (*head_a);
		ptr->index = 1;
		while (temp)
		{
			if (check_exist(ptr->arr, temp->i, ptr) == 1)
			{
				temp = temp->link;
				push_b(head_a, head_b, ptr->index, ptr);
				ptr->index = 1;
			}
			else
			{
				ptr->index++;
				temp = temp->link;
			}
		}
		ptr->end = ptr->end + ptr->offset;
		ptr->start = ptr->start - ptr->offset;
		if (ptr->end > ptr->len_array - 1)
			ptr->end = ptr->len_array - 1;
		if (ptr->start < 0)
			ptr->start = 0;
	}
}

void	push_a(t_list **head_a, t_list **head_b, t_struct *ptr, int index_max)
{
	int		index;
	int		count;
	t_list	*temp;

	while ((*head_b))
	{
		index = 1;
		temp = (*head_b);
		count = 0;
		while (temp)
		{
			if (temp->i == ptr->arr[index_max])
				break ;
			index++;
			temp = temp->link;
		}
		if (index <= ft_lstsize((*head_b)) / 2)
		{
			while ((*head_b)->i != ptr->arr[index_max])
			{
				if ((*head_b)->i == ptr->arr[index_max - 1])
				{
					pa(head_a, head_b);
					count = 1;
				}
				else
					rb(head_b, 1);
			}
		}
		else if (index > ft_lstsize((*head_b)) / 2)
		{
			while ((*head_b)->i != ptr->arr[index_max])
			{
				if ((*head_b)->i == ptr->arr[index_max - 1])
				{
					pa(head_a, head_b);
					count = 1;
				}
				else
					rrb(head_b, 1);
			}
		}
		pa(head_a, head_b);
		if (count == 1)
		{
			sa(head_a, 1);
			count = 0;
			index_max--;
		}
		index_max--;
	}
}

void	push_stack_a(t_list **head_a, t_list **head_b, t_struct *ptr)
{
	int	i;

	i = ft_lstsize((*head_b)) - 1;
	push_a(head_a, head_b, ptr, i);
}

void	sort_100(t_list **head_a, t_list **head_b, t_struct *ptr)
{
	initialize_struct(head_a, ptr);
	push_stack_b(head_a, head_b, ptr);
	push_stack_a(head_a, head_b, ptr);
}