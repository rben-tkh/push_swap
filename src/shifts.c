/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shifts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:38:52 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/07/06 22:54:25 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **lst, char *shift)
{
	t_list	*tmp;

	if (!*lst || !shift)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->prev = *lst;
	tmp->next = (*lst)->next;
	if ((*lst)->next)
		(*lst)->next->prev = tmp;
	(*lst)->next = tmp;
	(*lst)->prev = 0;
	write(1, shift, 2);
	write(1, "\n", 1);
}

void	push(t_list **lst, t_list **lst_2, char *shift)
{
	t_list	*tmp;

	if (!*lst || !shift)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	if (*lst)
		(*lst)->prev = 0;
	if (!*lst_2)
	{
		tmp->next = 0;
		*lst_2 = tmp;
	}
	else
	{
		tmp->next = *lst_2;
		(*lst_2)->prev = tmp;
		*lst_2 = tmp;
	}
	write(1, shift, 2);
	write(1, "\n", 1);
}

void	rotate(t_list **lst, char *shift)
{
	t_list	*tmp;

	if (!*lst || !shift)
		return ;
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	(*lst)->prev = tmp;
	tmp->next = *lst;
	*lst = (*lst)->next;
	(*lst)->prev->next = 0;
	(*lst)->prev = 0;
	write(1, shift, 2);
	write(1, "\n", 1);
}

void	reverse(t_list **lst, char *shift)
{
	t_list	*tmp;

	if (!*lst || !shift)
		return ;
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	(*lst)->prev = tmp;
	tmp->next = *lst;
	tmp->prev->next = 0;
	tmp->prev = 0;
	*lst = tmp;
	write(1, shift, 3);
	write(1, "\n", 1);
}

void	push_min(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;
	int		count;
	int		pos;
	int		pos2;

	if (!*lst_a || !*lst_b)
		return ;
	tmp = *lst_b;
	count = tmp->count;
	while (tmp->next)
	{
		if (count > tmp->next->count)
			count = tmp->next->count;
		tmp = tmp->next;
	}
	tmp = *lst_b;
	while (tmp->count != count)
			tmp = tmp->next;
	pos = tmp->pos;
	get_move(lst_b, pos, 1);
	pos2 = get_biggest(*lst_a, pos);
	get_move(lst_a, pos2, 0);
	push(lst_b, lst_a, "pa");
}
