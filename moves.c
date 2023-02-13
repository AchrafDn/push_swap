/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:25:44 by adadoun           #+#    #+#             */
/*   Updated: 2023/02/07 17:25:50 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	sa(t_list **head, int o)
{
	int	temp;

	if (head && ft_lstsize((*head)) > 1)
	{
		temp = (*head)->i;
		(*head)->i = (*head)->link->i;
		(*head)->link->i = temp;
		if (o == 1)
		{
			write(1, "sa\n", 3);
			return (1);
		}
	}
	return (0);
}

int	sb(t_list **head, int o)
{
	int	temp;

	if (head && ft_lstsize((*head)) > 1)
	{
		temp = (*head)->i;
		(*head)->i = (*head)->link->i;
		(*head)->link->i = temp;
		if (o == 1)
		{
			write(1, "sb\n", 3);
			return (1);
		}
	}
	return (0);
}

void	ss(t_list **head_a, t_list **head_b)
{
	int	i;
	int	j;

	i = sb(head_b, 0) != 0;
	j = sa(head_a, 0) != 0;
	if (i != 0 || j != 0)
		write(1, "ss\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*ptr;

	if (!a)
		return ;
	ft_lstadd_front((*b), ft_lstnew((*a)->i));
	ptr = (*a);
	(*a) = (*a)->link;
	free(ptr);
	write(1, "pb\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*ptr;

	if (!b)
		return ;
	ptr = (*b);
	(*b) = (*b)->link;
	ptr->link = (*a);
	(*a) = ptr;
	write(1, "pa\n", 3);
}

void	ra(t_list **head, int o)
{
	t_list	*ptr;
	t_list	*temp;

	if (!(*head) || ft_lstsize((*head)) < 2)
		return ;
	ptr = (*head);
	(*head) = (*head)->link;
	temp = (*head);
	while (temp && temp->link)
		temp = temp->link;
	temp->link = ptr;
	ptr->link = NULL;
	if (o == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **head, int o)
{
	t_list	*ptr;
	t_list	*temp;

	if (!(*head) || ft_lstsize((*head)) < 2)
		return ;
	ptr = (*head);
	(*head) = (*head)->link;
	temp = (*head);
	while (temp && temp->link)
		temp = temp->link;
	temp->link = ptr;
	ptr->link = NULL;
	if (o == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}

void	rra(t_list **head, int o)
{
	t_list	*temp2;
	t_list	*ptr;

	if (!(*head))
		return ;
	ptr = (*head);
	while (ptr && ptr->link->link)
		ptr = ptr->link;
	temp2 = ptr;
	ptr->link->link = (*head);
	(*head) = ptr->link;
	temp2->link = NULL;
	if (o == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list **head, int o)
{
	t_list	*temp2;
	t_list	*ptr;

	if (!(*head))
		return ;
	ptr = (*head);
	while (ptr && ptr->link->link)
		ptr = ptr->link;
	temp2 = ptr;
	ptr->link->link = (*head);
	(*head) = ptr->link;
	temp2->link = NULL;
	if (o == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rra(a, 0);
	rrb(b, 0);
	write(1, "rrr\n", 4);
}
