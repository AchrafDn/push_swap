/Users/adadoun/Library/Python/3.9/lib/python/site-packages/c_formatter_42/data/.clang-format                                                                                                                                                                                                                                                                                                                                                                                                                                                            +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 02:29:44 by adadoun           #+#    #+#             */
/*   Updated: 2023/02/10 02:29:45 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	parssing(char **av, t_list **head, int i)
{
	char	**str;
	int		j;
	int		nb;

	nb = 0;
	while (av[i])
	{
		j = -1;
		str = ft_split(av[i], ' '); //free
		if (*str == NULL)
			ft_error();
		while (str[++j])
		{
			if (ft_isdigit(str[j]) == 0)
				ft_error();
			nb = ft_atoi(str[j]);
			if (is_duplicate((*head), nb) == 0)
				ft_error();
			ft_lstadd_back(head, ft_lstnew(nb));
		}
		ft_free(str);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*temp;
	t_list	*head_b;
	int		i;

	// int		*arr;
	if (ac > 1)
	{
		parssing(av, &head, 1);
		is_sorted(head);
		if (ft_lstsize(head) == 2)
			sa(&head, 1);
		else if (ft_lstsize(head) == 3)
			sort_3(&head);
		else if (ft_lstsize(head) <= 5)
			sort_5(&head, &head_b);
		else if (ft_lstsize(head) <= 150)
			sort_5(&head, &head_b);
		i = 0;
		temp = head;
		while (head)
		{
			printf("a %i\n", head->i);
			head = head->link;
		}
		head = temp;
		pb(&head, &head_b);
		pb(&head, &head_b);
		while (head_b)
		{
			printf("b %i\n", head_b->i);
			head_b = head_b->link;
		}
		// arr = tab(head);
		// while (i < ft_lstsize(head))
		// {
		// 	printf("%i\n", arr[i]);
		// 	i++;
		// }
		// write(1, "\n", 1);
		// i = 0;
		// sort_tab(arr, ft_lstsize(head));
		// while (i < ft_lstsize(head))
		// {
		// 	printf("%i\n", arr[i]);
		// 	i++;
		// }
	}
}
