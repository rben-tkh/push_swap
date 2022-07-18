/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:22:13 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/07/07 05:40:31 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_list **lst)
{
	t_data	data;

	data.a = (*lst)->pos;
	data.b = (*lst)->next->pos;
	data.c = (*lst)->next->next->pos;
	if (data.a > data.b && data.a < data.c && data.b < data.c)
		swap(lst, "sa");
	else if (data.a > data.b && data.a > data.c && data.b < data.c)
		rotate(lst, "ra");
	else if (data.a < data.b && data.a > data.c && data.b > data.c)
		reverse(lst, "rra");
	else if (data.a < data.b && data.a < data.c && data.b > data.c)
	{
		swap(lst, "sa");
		rotate(lst, "ra");
	}
	else if (data.a > data.b && data.a > data.c && data.b > data.c)
	{
		swap(lst, "sa");
		reverse(lst, "rra");
	}
}

static void	push_smallest(t_list **lst_a, t_list **lst_b)
{
	int	pos;

	pos = (*lst_a)->pos;
	while ((*lst_a)->next)
	{
		if ((*lst_a)->pos < pos)
			pos = (*lst_a)->pos;
		*lst_a = (*lst_a)->next;
	}
	if ((*lst_a)->pos < pos)
		pos = (*lst_a)->pos;
	while ((*lst_a)->prev)
		*lst_a = (*lst_a)->prev;
	get_move(lst_a, pos, 0);
	push(lst_a, lst_b, "pb");
}

static void	sort_other(t_list **lst_a, t_list **lst_b, int size)
{
	int	i;

	i = size;
	while (i--)
	{
		if ((*lst_a)->pos < ((size / 2) + (size / 4)))
			push(lst_a, lst_b, "pb");
		else
			rotate(lst_a, "ra");
		if (*lst_b && (*lst_b)->pos < (size / 3))
			rotate(lst_b, "rb");
	}
	while ((*lst_a)->next->next)
	{
		if ((*lst_a)->pos == (size - 1))
			rotate(lst_a, "ra");
		push(lst_a, lst_b, "pb");
	}
	while (*lst_b)
	{
		lst_initcount(*lst_a, *lst_b);
		push_min(lst_a, lst_b);
	}
	get_move(lst_a, 0, 0);
}

static void	sort_list(t_list **lst_a, t_list **lst_b, int size)
{
	if (!*lst_a || size < 2)
		return ;
	if (size == 2)
		swap(lst_a, "sa");
	else if (size == 3)
		sort_three(lst_a);
	else if (size == 4)
	{
		push_smallest(lst_a, lst_b);
		sort_three(lst_a);
		push(lst_b, lst_a, "pa");
	}
	else if (size == 5)
	{
		push_smallest(lst_a, lst_b);
		push_smallest(lst_a, lst_b);
		sort_three(lst_a);
		push(lst_b, lst_a, "pa");
		push(lst_b, lst_a, "pa");
	}
	else
		sort_other(lst_a, lst_b, size);
}

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	int		size;

	if (ac == 1 || !av)
		return (0);
	lst_a = lst_create(av);
	lst_b = 0;
	if (!lst_a || check_args(av) == -1 || check_dup(lst_a) == -1)
	{
		lst_clear(&lst_a);
		write(2, "Error\n", 6);
		return (-1);
	}
	size = get_size(lst_a);
	if (size == 1 || check_sort(lst_a))
	{
		lst_clear(&lst_a);
		return (0);
	}
	sort_list(&lst_a, &lst_b, size);
	lst_clear(&lst_a);
	return (0);
}
