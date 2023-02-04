#include "header.h"

void	ft_error()
{
	write(2, "Error\n", 6);
	exit(0);
}

void	ft_free(char **ptr)
{
	int i;

	i = 0;
	while(ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
void	is_duplicate(t_list	*head, int nb)
{
	while(head)
	{
		if (head->i == nb)
			ft_error();
		head = head->link;
	}
}
int	*tab(t_list *head)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * ft_lstsize(head));
	while(head)
	{
		arr[i] = head->i;
		head = head->link;
		i++;
	}
	return(arr);
}
int main(int ac, char **av)
{
	char	**str;
	t_list	*head;
	t_list	*temp;
	int	j = 0;
	int nb = 0;
	int i;

	i = 1;
	if(ac > 1)
	{
		while(av[i])
		{
			j = 0;
			str = ft_split(av[i], ' ');//free
			if (*str == NULL)
				ft_error();
			while(str[j])
			{
				if(ft_isdigit(str[j]) == 0)
				{
					ft_free(str);
					ft_error();
				}
				nb = ft_atoi(str[j]);
				is_duplicate(head, nb);
				ft_lstadd_back(&head, ft_lstnew(nb));
				j++;
			}
			ft_free(str);
			i++;
		}
		temp = head;
		while(head)
		{
			printf("%d\n", head->i);
			head = head->link;
		}
		head = temp;
		int	*arr;
		i = 0;
		arr = tab(head);
		while(arr[i])
		{
			printf("......%i\n", arr[i]);
			i++;
		}
	}
}