/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:27:23 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/07/04 21:20:40 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count(char *str)
{
	int	i;
	int	count;
	int	nb_char;

	i = 0;
	count = 0;
	nb_char = 0;
	while (str && str[i])
	{
		if ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
			nb_char = 0;
		if (str[i] != '0' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
			nb_char++;
		if ((str[i] >= '0' && str[i] <= '9')
			&& ((str[i + 1] >= '\t' && str[i + 1] <= '\r')
				|| (str[i + 1] == ' ' || !str[i + 1])))
			count++;
		if ((str[i] >= '0' && str[i] <= '9')
			&& (str[i + 1] == '-' || str[i + 1] == '+' || nb_char > 10))
			return (-1);
		i++;
	}
	if (count < 1)
		return (-1);
	return (count);
}

long	ft_atoi(char *str, int pos)
{
	static int	i;
	int			n;
	long		nb;

	if (pos == 1)
		i = 0;
	n = 1;
	nb = 0;
	while ((str && (str[i] >= '\t' && str[i] <= '\r')) || str[i] == ' ')
		i++;
	if (str && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	if (!str || !(str[i] >= '0' && str[i] <= '9'))
		return (ERROR);
	while (str[i] >= '0' && str[i] <= '9')
		nb = nb * 10 + (str[i++] - '0');
	nb *= n;
	n = (int)nb;
	if (n != nb)
		return (ERROR);
	return (nb);
}

int	check_args(char **av)
{
	int		i;
	int		j;
	int		k;

	i = 1;
	while (av && av[i])
	{
		j = 0;
		while (av[i][j])
		{
			k = 0;
			while (SET[k])
			{
				if (av[i][j] == SET[k])
					break ;
				k++;
			}
			if (SET[k] == '\0')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_dup(t_list *lst)
{
	t_list	*next;

	if (!lst)
		return (0);
	while (lst)
	{
		if (lst->nb == ERROR)
			return (-1);
		next = lst->next;
		while (next)
		{
			if (lst->nb == next->nb)
				return (-1);
			next = next->next;
		}
		lst = lst->next;
	}
	return (0);
}

int	check_sort(t_list *lst)
{
	if (!lst)
		return (1);
	while (lst->next)
	{
		if (lst->pos > lst->next->pos)
			return (0);
		lst = lst->next;
	}
	return (1);
}
