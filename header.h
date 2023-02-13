/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adadoun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:24:36 by adadoun           #+#    #+#             */
/*   Updated: 2023/02/07 17:24:39 by adadoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct nod
{
	int			i;
	struct nod	*link;
}				t_list;
//sorts
void			sort_3(t_list **head);
void			sort_5(t_list **head_a, t_list **head_b);
void			sort_100(t_list **head_a, t_list **head_b);
//utils3
void			ft_error(void);
void			ft_free(char **ptr);
size_t			ft_strlen(const char *str);
//utils2
int				*tab(t_list *head);
void			is_sorted(t_list *head);
int				is_duplicate(t_list *head, int nb);
int				ft_isdigit(char *str);
//utils1
t_list			*ft_lstnew(int content);
int				ft_lstsize(t_list *lst);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			*ft_lstlast(t_list *lst);
//files
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(const char *s, char c);
int				ft_atoi(const char *str);
//moves
int				sa(t_list **head, int o);
int				sb(t_list **head, int o);
void			ss(t_list **head_a, t_list **head_b);
void			pb(t_list **a, t_list **b);
void			pa(t_list **a, t_list **b);
void			ra(t_list **head, int o);
void			rb(t_list **head, int o);
void			rr(t_list **a, t_list **b);
void			rra(t_list **head, int o);
void			rrb(t_list **head, int o);
void			rrr(t_list **a, t_list **b);

#endif
