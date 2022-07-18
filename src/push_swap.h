/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rben-tkh <rben-tkh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 17:23:16 by rben-tkh          #+#    #+#             */
/*   Updated: 2022/07/07 05:34:04 by rben-tkh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define ERROR 2147483648
# define SET "+-0123456789 \t\n\r\v\f"

# include <unistd.h>
# include <stdlib.h>

/*-------------------------------------LIST----------------------------------*/

typedef struct s_list
{
	long			nb;
	int				pos;
	int				count;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

/*-------------------------------------DATA----------------------------------*/

typedef struct s_data
{
	long	a;
	long	b;
	long	c;
}	t_data;

/*------------------------------------LISTS----------------------------------*/

t_list	*lst_create(char **av);
void	lst_initcount(t_list *lst_a, t_list *lst_b);
void	lst_clear(t_list **lst);

/*------------------------------------PARSING--------------------------------*/

int		ft_count(char *str);
long	ft_atoi(char *str, int pos);
int		check_args(char **av);
int		check_dup(t_list *lst);
int		check_sort(t_list *lst);

/*------------------------------------SHIFTS---------------------------------*/

void	swap(t_list **lst, char *shift);
void	push(t_list **lst, t_list **lst_2, char *shift);
void	rotate(t_list **lst, char *shift);
void	reverse(t_list **lst, char *shift);
void	push_min(t_list **lst_a, t_list **lst_b);

/*------------------------------------UTILS----------------------------------*/

int		get_size(t_list *lst);
int		get_biggest(t_list *lst, int pos);
int		get_count(t_list *lst, int pos);
void	get_move(t_list **lst, int pos, int i);

#endif
