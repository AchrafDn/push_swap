#ifndef HEADER_H
# define HEADER_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct nod{
    int i;
    struct nod *link;
}t_list;

//utils
void	ft_error();
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list  *ft_lstlast(t_list *lst);
int     ft_isdigit(char *str);
t_list	*ft_lstnew(int  content);
int		ft_lstsize(t_list *lst);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(const char *s, char c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
//moves
int		sa(t_list **head, int o);
int		sb(t_list **head, int o);
void	ss(t_list **head_a, t_list **head_b);
void	pb(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	ra(t_list **head, int o);
void	rb(t_list **head, int o);
void	rr(t_list **a, t_list **b);
void	rra(t_list **head, int o);
void	rrb(t_list **head, int o);
void	rrr(t_list **a, t_list **b);
#endif