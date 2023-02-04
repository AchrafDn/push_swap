#include "header.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		p;
	size_t	res;

	res = 0;
	p = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			p = -1;
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		res = (res * 10) + (str[i] - 48);
		if (res > 2147483647)
			ft_error();
		i++;
	}
	return (res * p);
}