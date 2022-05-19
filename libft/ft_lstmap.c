/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkuokkan <kkuokkan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 13:29:57 by kkuokkan          #+#    #+#             */
/*   Updated: 2021/12/03 11:03:32 by kkuokkan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstdel1(t_list *alst)
{
	if (alst == NULL)
		return ;
	ft_lstdel1(alst->next);
	if (alst->content != NULL)
		free (alst->content);
	free (alst);
	alst = NULL;
}

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_begin;
	t_list	*new;

	if (lst == NULL)
		return (NULL);
	new_begin = f(lst);
	new = new_begin;
	while (lst->next != NULL)
	{
		new->next = f(lst->next);
		if (new->next == NULL)
		{
			ft_lstdel1(new_begin);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (new_begin);
}
