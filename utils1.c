/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:10:29 by adadoun           #+#    #+#             */
/*   Updated: 2023/02/07 17:10:32 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		temp = ft_lstlast(*lst);
		temp->link = new;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst->link)
	{
		lst = lst->link;
	}
	return (lst);
}

t_list	*ft_lstnew(int content)
{
	t_list	*p;

	p = malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	p->i = content;
	p->link = NULL;
	return (p);
}

int	ft_lstsize(t_list *lst)
{
	int	c;

	if (!lst)
		return (0);
	c = 0;
	while (lst)
	{
		c = c + 1;
		lst = lst->link;
	}
	return (c);
}
