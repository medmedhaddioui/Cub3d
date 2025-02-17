/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noudrib <noudrib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:14:52 by noudrib           #+#    #+#             */
/*   Updated: 2023/11/12 14:29:46 by noudrib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lst_fill(t_list **new, t_list *cur, void *(*f)(void *), void (*del)
			(void *))
{
	void	*temp;
	t_list	*temp2;

	while (cur)
	{
		temp = f(cur -> content);
		temp2 = ft_lstnew(temp);
		if (!temp2)
		{
			del(temp);
			ft_lstclear(new, del);
			return (0);
		}
		ft_lstadd_back(new, temp2);
		cur = cur -> next;
	}
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*current;
	void	*temp;

	if (!lst || !f || !del)
		return (NULL);
	temp = f(lst -> content);
	new = ft_lstnew(temp);
	if (!new)
	{
		del(temp);
		return (NULL);
	}
	current = lst -> next;
	if (!lst_fill(&new, current, f, del))
		return (NULL);
	return (new);
}
