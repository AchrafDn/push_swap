/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 02:18:07 by adadoun           #+#    #+#             */
/*   Updated: 2023/02/10 02:18:09 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_chrmin(t_list *head)
{
	int	v;
	int	i;
	int	index;

	v = head->i;
	i = 1;
	index = 1;
	while (head)
	{
		if (head->i < v)
		{
			v = head->i;
			index = i;
		}
		head = head->link;
		i++;
	}
	return (index);
}

void	sort_5(t_list **head_a, t_list **head_b)
{
	int	min;
	int	size;

	while (ft_lstsize((*head_a)) > 3)
	{
		min = ft_chrmin((*head_a));
		size = ft_lstsize((*head_a)) / 2;
		if (min > size)
		{
			while (min++ <= ft_lstsize((*head_a)))
				rra(head_a, 1);
		}
		else if (min != 1 && min <= size)
		{
			while (min-- > 1)
				ra(head_a, 1);
		}
		pb(head_a, head_b);
	}
	sort_3(head_a);
	while (ft_lstsize((*head_b)) > 0)
		pa(head_a, head_b);
}
