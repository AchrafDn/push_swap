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

int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (i == 0 && (str[0] == '-' || str[0] == '+'))
			i++;
		if (str[i] <= '9' && str[i] >= '0')
			i++;
		else
			return (0);
	}
	return(1);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

t_list  *ft_lstnew(int  content)
{
        t_list  *p;

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


// t_list  *create_list(t_list *head, int *data)
// {
//     t_list  *temp;

//     temp = malloc(sizeof(t_list));
//     head->i = data[0];
//     head->link = NULL;
//     temp->i = data[1];
//     temp->link = NULL;
//     head->link = temp;
//     temp = malloc(sizeof(t_list));
//     temp->i = data[2];
//     temp->link = NULL;
//     head->link->link= temp;
//     return(head);
// }