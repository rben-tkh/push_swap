/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 01:40:13 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/07/07 05:39:21 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	lst_newback(t_list **lst, long nb)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->nb = nb;
	new->pos = 0;
	new->count = 0;
	new->next = 0;
	if (!*lst)
	{
		new->prev = 0;
		*lst = new;
		return ;
	}
	while ((*lst)->next)
		*lst = (*lst)->next;
	new->prev = *lst;
	(*lst)->next = new;
	while ((*lst)->prev)
		*lst = (*lst)->prev;
}

static void	lst_initpos(t_list *lst)
{
	t_list	*tmp;
	t_list	*head;

	if (!lst)
		return ;
	head = lst;
	while (lst)
	{
		tmp = head;
		lst->pos = 0;
		while (tmp)
		{
			if (lst->nb > tmp->nb)
				lst->pos++;
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

t_list	*lst_create(char **av)
{
	t_list	*lst;
	int		i;
	int		count;
	int		pos;

	if (!av)
		return (0);
	lst = 0;
	i = 1;
	while (av[i])
	{
		if (ft_count(av[i]) == -1)
			return (lst_clear(&lst), NULL);
		else
			count = ft_count(av[i]);
		pos = 1;
		while (count--)
		{
			lst_newback(&lst, ft_atoi(av[i], pos));
			pos = 0;
		}
		i++;
	}
	lst_initpos(lst);
	return (lst);
}

void	lst_initcount(t_list *lst_a, t_list *lst_b)
{
	t_list	*tmp;
	int		pos;
	int		count;
	int		count2;

	if (!lst_a || !lst_b)
		return ;
	tmp = lst_b;
	while (tmp)
	{
		pos = get_biggest(lst_a, tmp->pos);
		count = get_count(lst_b, tmp->pos);
		count2 = get_count(lst_a, pos);
		if (count == -1 || count2 == -1)
			return ;
		tmp->count = count + count2;
		tmp = tmp->next;
	}
}

void	lst_clear(t_list **lst)
{
	if (!*lst)
		return ;
	while ((*lst)->next)
	{
		*lst = (*lst)->next;
		free((*lst)->prev);
		(*lst)->prev = 0;
	}
	free(*lst);
	*lst = 0;
}
