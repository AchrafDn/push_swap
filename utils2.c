/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:08:30 by adadoun           #+#    #+#             */
/*   Updated: 2023/02/07 17:08:32 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[0] == '-' || str[0] == '+'))
			i++;
		if (str[i] <= '9' && str[i] >= '0')
			i++;
		else
			return (0);
	}
	return (1);
}

int	is_duplicate(t_list *head, int nb)
{
	while (head)
	{
		if (head->i == nb)
			return (0);
		head = head->link;
	}
	return (1);
}

void	is_sorted(t_list *head)
{
	int	i;

	i = 0;
	while (head->link)
	{
		if (head->i >= head->link->i)
		{
			i = 1;
			break ;
		}
		head = head->link;
	}
	if (i == 0)
		exit(0);
}

int	*tab(t_list *head)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * ft_lstsize(head));
	if (!arr)
		ft_error();
	while (head)
	{
		arr[i] = head->i;
		head = head->link;
		i++;
	}
	return (arr);
}
