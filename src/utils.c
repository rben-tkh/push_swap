/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:33:08 by soabbas           #+#    #+#             */
/*   Updated: 2022/07/07 05:34:22 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_size(t_list *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

int	get_biggest(t_list *lst, int pos)
{
	t_list	*tmp;
	int		i;

	if (!lst)
		return (0);
	tmp = lst;
	i = pos;
	while (lst)
	{
		if (i < lst->pos)
		{
			pos = lst->pos;
			break ;
		}
		lst = lst->next;
	}
	while (tmp)
	{
		if (pos > tmp->pos && tmp->pos > i)
			pos = tmp->pos;
		tmp = tmp->next;
	}
	return (pos);
}

int	get_count(t_list *lst, int pos)
{
	int	i;
	int	j;

	if (!lst)
		return (-1);
	i = 0;
	while (lst && lst->pos != pos)
	{
		lst = lst->next;
		i++;
	}
	j = 0;
	while (lst)
	{
		j++;
		lst = lst->next;
	}
	if (i <= j)
		return (i);
	return (j);
}

static int	get_pos(t_list *lst, int pos)
{
	int	i;
	int	size;

	if (!lst)
		return (-1);
	i = 0;
	size = get_size(lst);
	while (lst->pos != pos)
	{
		i++;
		lst = lst->next;
	}
	if (i <= (size / 2))
		return (1);
	return (0);
}

void	get_move(t_list **lst, int pos, int i)
{
	if (*lst && i == 0)
	{
		if (get_pos(*lst, pos) == 1)
		{
			while ((*lst)->pos != pos)
				rotate(lst, "ra");
		}
		else if (get_pos(*lst, pos) == 0)
		{
			while ((*lst)->pos != pos)
				reverse(lst, "rra");
		}
		return ;
	}
	if (*lst && get_pos(*lst, pos) == 1)
	{
		while ((*lst)->pos != pos)
			rotate(lst, "rb");
	}
	else if (*lst && get_pos(*lst, pos) == 0)
	{
		while ((*lst)->pos != pos)
			reverse(lst, "rrb");
	}
}
