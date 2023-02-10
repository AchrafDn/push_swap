/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 02:19:31 by adadoun           #+#    #+#             */
/*   Updated: 2023/02/10 02:19:33 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_3(t_list **head)
{
	int	a;
	int	b;
	int	c;

	a = (*head)->i;
	b = (*head)->link->i;
	c = (*head)->link->link->i;
	if (b < a && a < c)
		sa(head, 1);
	else if (a < b && a > c)
		rra(head, 1);
	else if (a > b && b > c)
	{
		sa(head, 1);
		rra(head, 1);
	}
	else if (a > b && b < c)
		ra(head, 1);
	else if (a < b && b > c)
	{
		rra(head, 1);
		sa(head, 1);
	}
}
